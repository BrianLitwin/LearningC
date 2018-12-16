#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 100
#define MAX_ROWS 512

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void die(char *message) {
  if (errno) {
    perror("message");
  } else {
    printf("%s\n", message);
  }

  exit(1);
}

void Address_print(struct Address *addr) {
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {
   int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
   if (rc != 1)
       die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn) {
    die("Failed to create *conn");
  }

  conn->db = malloc(sizeof(struct Database));

  if (mode == 'c') {
    conn->file = fopen(filename, "w");

  } else {
    conn->file = fopen(filename, "r+");
    if (conn->file) {
        Database_load(conn);
    }
  }

  if (!conn->file) {
    die("failed to open file");
  }

  return conn;
}


void Database_close(struct Connection *conn) {
  if (conn) {
    if (conn->file) {
      fclose(conn->file);
    }
    if (conn->db) {
      free(conn->db);
    }
    free(conn);
  }
}


void Database_write(struct Connection *conn) {
  rewind(conn->file);
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1) {
    die("Failed to load connection");
  }

  rc = fflush(conn->file);
  if (rc == -1) {
    die("Cannot flush database");
  }
}



void Database_create(struct Connection *conn) {
  int i = 0;
  for (i=0; i<MAX_ROWS; i++) {
    struct Address addr = { .id = i, .set = 0 };
    conn->db->rows[i] = addr;
  }
}

void Database_set(
  struct Connection *conn,
  int id,
  char *name,
  char *email
) {
  struct Address *addr = &conn->db->rows[id];
  addr->set = 1;
  char *res = strncpy(addr->name, name, MAX_DATA);
  res = strncpy(addr->email, email, MAX_DATA);
  if (!res) {
    die("couldn't copy email string to db->email");
  }

}

void Database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id];
  Address_print(addr);
}

void Database_delete(struct Connection *conn, int id) {
  struct Address addr = { .id = 0, .set = 0 };
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
  int i = 0;
  struct Database *db = conn->db;

  for (i=0; i<MAX_ROWS; i++) {
    struct Address *addr = &db->rows[i];
    if (addr->set) {
      Address_print(addr);
    }
  }
}


int main(int argc, char *argv[]) {
   if (argc < 3)
       die("USAGE: ex17 <dbfile> <action> [action params]");

  // make a pointer of type char called filename
  // and set it to the element at index 1 of argv
   char *filename = argv[1];

   // make a pointer of type char called action
   // and set it to the element at index 0 of the
   // element at index 2 of argv
   char action = argv[2][0];

   struct Connection *conn = Database_open(filename, action);
   int id = 0;

   if (argc > 3) id = atoi(argv[3]);
   if (id >= MAX_ROWS) die("There's not that many records.");

   switch (action) {
       case 'c':
           Database_create(conn);
           Database_write(conn);
           break;

       case 'g':
           if (argc != 4)
               die("Need an id to get");

           Database_get(conn, id);
           break;

       case 's':
           if (argc != 6)
               die("Need id, name, email to set");

           Database_set(conn, id, argv[4], argv[5]);
           Database_write(conn);
           break;

       case 'd':
           if (argc != 4)
               die("Need id to delete");

           Database_delete(conn, id);
           Database_write(conn);
           break;

       case 'l':
           Database_list(conn);
           break;
       default:
           die("Invalid action: c=create, g=get, s=set, d=del, l=list");
   }

   Database_close(conn);

   return 0;
}
