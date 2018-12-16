// include the header file
// printf, fwrite, fwrite
#include <stdio.h>

// assert
#include <assert.h>

// exit, free
#include <stdlib.h>

// errno
#include <errno.h>

// strncpy
#include <string.h>

//
#define MAX_DATA 512
#define MAX_ROWS 100

// define a struct called Address w/
// the properties id and set of type int
// an array of chars of size 512 called name
// an array of chars called email of size 512
struct Address {
   int id;
   int set;
   char name[MAX_DATA];
   char email[MAX_DATA];
};

// define a struct called database
// with a property named rows that is an
// array of type Address and size max_rows
struct Database {
   struct Address rows[MAX_ROWS];
};

// define a struct called Connection
// with properties file,
// a pointer of type File named file
// a pointer of type Database named db
struct Connection {
   FILE *file;
   struct Database *db;
};

// a function that returns void and
// exits the program
// a pointer of type char named messsage
void die(const char *message) {
   if (errno) {
      // print the error if their is one
       perror(message);
   } else {
       printf("ERROR: %s\n", message);
   }

   // exit the program
   exit(1);
}

// print Address's properties
// take a pointer to address as a paramter
// print variables using pointer syntax
void Address_print(struct Address *addr) {
   printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// fread
void Database_load(struct Connection *conn) {

  // if you need to read the contents of the file
  // first take them from the file and transfer them into
  // the conn->db variable

  // This reads the contents of a structure
  // variable from the file and stores
  // it in the variable conn->db.
   int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
   if (rc != 1)
       die("Failed to load database.");
}

// a function that opens a file in the database
// take a pointer of type char named filename and a variable of type char named mode
struct Connection *Database_open(const char *filename, char mode) {
  // a pointer of type Connection
   struct Connection *conn = malloc(sizeof(struct Connection));
   if (!conn) {
       die("Memory error");
     }

   conn->db = malloc(sizeof(struct Database));
   if (!conn->db) {
       die("Memory error");
    }

   if (mode == 'c') {
       conn->file = fopen(filename, "w");
   } else {
       conn->file = fopen(filename, "r+");

       if (conn->file) {
           Database_load(conn);
       }
   }

   if (!conn->file) {
       die("Failed to open the file");
    }

   return conn;
}


// close the database connection by close the file,
// free the databse variable in connection and freeing
// connection
void Database_close(struct Connection *conn) {
   if (conn) {
       if (conn->file)
           fclose(conn->file);
       if (conn->db)
           free(conn->db);
       free(conn);
   }
}

// write the structure db contents into a file stored in Conn
void Database_write(struct Connection *conn) {
   rewind(conn->file);

   int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
   if (rc != 1)
       die("Failed to write database.");

   rc = fflush(conn->file);
   if (rc == -1)
       die("Cannot flush database.");
}

/*
create an Address with an id of i and set state = 0
assign it to the appropriate area
*/

void Database_create(struct Connection *conn) {
   int i = 0;

   for (i = 0; i < MAX_ROWS; i++) {
       // make a prototype to initialize it
       struct Address addr = {.id = i,.set = 0 };
       // then just assign it
       conn->db->rows[i] = addr;
   }
}

void Database_set(
  struct Connection *conn,
  int id,
  const char *name,
  const char *email) {
   struct Address *addr = &conn->db->rows[id];
   if (addr->set)
       die("Already set, delete it first");

   addr->set = 1;
   // WARNING: bug, read the "How To Break It" and fix this
   char *res = strncpy(addr->name, name, MAX_DATA);
   // demonstrate the strncpy bug
   if (!res)
       die("Name copy failed");

   res = strncpy(addr->email, email, MAX_DATA);
   if (!res)
       die("Email copy failed");
}

void Database_get(struct Connection *conn, int id) {
    // set to the address of the Address at index id of the rows variable in database in connection
   struct Address *addr = &conn->db->rows[id];

   if (addr->set) {
       Address_print(addr);
   } else {
       die("ID is not set");
   }
}

void Database_delete(struct Connection *conn, int id) {
   struct Address addr = { .id = id, .set = 0 };
   conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
   int i = 0;
   struct Database *db = conn->db;

   for (i = 0; i < MAX_ROWS; i++) {
       struct Address *cur = &db->rows[i];

       if (cur->set) {
           Address_print(cur);
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
