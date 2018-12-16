
write a shell script that prints 'hello world!' to the console
<details>

```
#!/bin/bash
echo "Hello World"
```

in terminal: `chmod 755 helloworld`

</details>

what is errno?
<details>

```
The <errno.h> header file defines the integer variable errno, which
is set by system calls and some library functions in the event of an
error to indicate what went wrong.
```

</details>

what does `fopen` do?
<details>

Declaration:
fopen(const char * restrict path, const char * restrict mode);

The fopen() function opens the file whose name is the string pointed to
by path and associates a stream with it.

The argument mode points to a string beginning with one of the following
letters:

``r''   Open for reading.  The stream is positioned at the beginning of
        the file.  Fail if the file does not exist.

``w''   Open for writing.  The stream is positioned at the beginning of
        the file.  Create the file if it does not exist.

``a''   Open for writing.  The stream is positioned at the end of the
        file.  Subsequent writes to the file will always end up at the
        then current end of file, irrespective of any intervening
        fseek(3) or similar.  Create the file if it does not exist.

An optional ``+'' following ``r'', ``w'', or ``a'' opens the file for
both reading and writing.  An optional ``x'' following ``w'' or ``w+''
causes the fopen() call to fail if the file already exists.  An optional
``e'' following the above causes the fopen() call to set the FD_CLOEXEC
flag on the underlying file descriptor.

</details>

what does `exit()` do?

<details>
The C library function void exit(int status) terminates the calling process immediately. Any open file descriptors belonging to the process are closed and any children of the process are inherited by process 1, init, and the process parent is sent a SIGCHLD signal.
</details>

what does `perror()` do?
<details>

The C library function void perror(const char *str)
prints a descriptive error message to stderr.
First the string str is printed, followed by a colon then a space.

</details>

Write a program that asks to open a file that doesn't exist and use `perrror()`

<details>

```
#include <stdio.h>

int main() {
  FILE *fp;
  fp = fopen("a_file_that_doesn't_exist", "r");
  if ( fp == NULL ) {
    perror("Error Message"); // note: no colon  
    return(-1);
  }

  fclose(fp);
  return(0);
}

// prints `Error Message: No such file or directory`

```

</details>

what does `fread()` do?

<details>

The function fread() reads nitems objects, each size bytes long, from the
stream pointed to by stream, storing them at the location given by ptr.

fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);

Following is the declaration for fread() function:
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

Parameters:
ptr − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
size − This is the size in bytes of each element to be read.
nmemb − This is the number of elements, each one with a size of size bytes.
stream − This is the pointer to a FILE object that specifies an input stream.

The total number of elements successfully read are returned as a size_t object,
which is an integral data type. If this number differs from the nmemb parameter,
then either an error had occurred or the End Of File was reached.

</details>

Make an example of `fread()`
<details>

```
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char c[] = "this is tutor";
    char buffer[100];

    // open file for both reading and writing
    fp = fopen("file.txt", "w+");

    // write data to the file
    fwrite(c, strlen(c) + 1, 1, fp);

    // seek to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // read and display the data
    fread(buffer, strlen(c) + 1, 1, fp);
    printf("%s \n", buffer);
    fclose(fp);

    return 0;
}
```
</details>

what does `rewind()` do?
<details>

The C library function void rewind(FILE *stream) sets the file position to the beginning of the file of the given stream.

decl:
void rewind(FILE *stream)

stream − This is the pointer to a FILE object that identifies the stream.

</details>

what does `fwrite` do?

<details>

The C library function size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) writes data from the array pointed to, by ptr to the given stream.

Declaration -
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
Parameters
ptr − This is the pointer to the array of elements to be written.
size − This is the size in bytes of each element to be written.
nmemb − This is the number of elements, each one with a size of size bytes.
stream − This is the pointer to a FILE object that specifies an output stream.

Return Value -
This function returns the total number of elements successfully returned as a size_t object,
which is an integral data type. If this number differs from the nmemb parameter, it will show an error.

</details>

Do an example of `fwrite`
<details>

```
#include<stdio.h>

int main () {
   FILE *fp;
   char str[] = "This is tutorialspoint.com";

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);

   return(0);
}

// should create a file
```

</details>

what does `#define` do?
<details>
the #define directive allows the definition of macros within your source code. These macro definitions allow constant values to be declared for use throughout your code.

Macro definitions are not variables and cannot be changed by your program code like variables. You generally use this syntax when creating constants that represent numbers, strings or expressions.
</details>



What does `fflush` do ??
<details>

The C library function int fflush(FILE *stream) flushes the output buffer of a stream.
declaration:
int fflush(FILE *stream)
stream − This is the pointer to a FILE object that specifies a buffered stream.
Return Value:
This function returns a zero value on success.
If an error occurs, EOF is returned and the error indicator is set (i.e. feof).

</details>

what does `strncpy()` do?
<details>
The C library function char *strncpy(char *dest, const char *src, size_t n) copies up to n characters from the string pointed to, by src to dest. In a case where the length of src is less than that of n, the remainder of dest will be padded with null bytes.

char *strncpy(char *dest, const char *src, size_t n)

dest − This is the pointer to the destination array where the content is to be copied.
src − This is the string to be copied.
n − The number of characters to be copied from source.

eg.,
char *res = strncpy(addr->name, name, MAX_DATA);
is copying the string name to the variable name in the struct address

This function returns the final copy of the copied string.

</details>

What does `aoi()` do?
<details>

The C library function int atoi(const char *str)
converts the string argument str to an integer (type int).
This function returns the converted integral number as an int value.
If no valid conversion could be performed, it returns zero.

int atoi(const char *str)

paramteter str − This is the string representation of an integral number.


</details>  

Give at example of `atoi()`
<details>

```
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%d\n", atoi("4"));
  // prints 4

  printf("%d\n", atoi("F"));
  // prints 0

  return 0;
}

```
</details>

What does Zed's database program do?

<details>

create two constants, maxData and maxRows

Creates three structs, `Address`, `Database`, and `Connection`.
`Address` holds a person's info: id, set, name, email.
`Database` holds an array of `Addresses`.
`Connection` holds a pointer of type `Database` and a pointer of type `File`.

* a function called `die` that prints an error
  * checks errno and if thats set to NULL, prints the message passed in as a parameter
  and exits the program
* a function `Address_print` that prints the Address's properties
  * print the id, name, and email
* Create a function called `Database_load` that takes a `Connection` as
  a parameter and reads the contents of its file into
  a database structure so that you can access them as a database structure
  * fill in `Conn`'s db parameter w its file param  
  * check to make sure `fread` worked
* Create function called `Database_open` that returns a pointer of type `Connection`
  * take a filename and mode and create a `Connection` by creating a new database variable
  and a either creating or reading the file w/ `Database_load`
* Create a function called `Database_close` that frees the memory in `Connection`
* `Database_write` writes the contents of a `Database` into a file held by `Connection`
* Create a function called `Database_create` that makes 512 unset address entries in the database
* Create a function called `Database_set` that takes id, name, and email parameters, and writes them
into the database
* `database_get`: print the `Address` properties of the `Address` row at the given index, inside
  the db of the given `Connection`   
* Create a function called `Database_print` that takes a connection and index and prints
  the `Address` at that index
* Create a function called `Database_list` that prints all the prints all the set rows in the database

pass in the parameters through the command line:
`<dbfile> <action> [action params]`

in a switch statement, handle 5 actions: c, g, s, d, l to pass in as <action>

* c: create the database connection
  * `db.dat c`
* g: get the info at row i
  * `db.dat s 1 zed zed@zedshaw.com`
* s: set the info (given id, name, address) in the database
  * eg: `db.dat s 1 zed zed@zedshaw.com`
* d: delete the info at row i
  * eg `db.dat d 3`
* l: list the items in the db
  * eg `db.dat l`

</details>

## How to Break It

* The classic way is to remove some of the safety checks so that you can pass in arbitrary data. For example, remove the check on line 160 that prevents you from passing in any record number.

* ???

* You can also try corrupting the data file. Open it in any editor and change random bytes, and then close it.

* ???

* You could also find ways to pass bad arguments to the program when it's run. For example, getting the file and action backwards will make it create a file named after the action, and then do an action based on the first character.

* ???

* There's a bug in this program because strncpy is poorly designed. Go read about strncpy and try to find out what happens when the name or address you give is greater than 512 bytes. Fix this by simply forcing the last character to '\0' so that it's always set no matter what (which is what strncpy should do).

* ???

* In the extra credit, I have you augment the program to create arbitrary size databases. Try to see what the biggest database is before you cause the program to die due to lack of memory from malloc.

* ???

## Extra Credit

* The die function needs to be augmented to let you pass the conn variable, so it can close it and clean up.

* add `struct Connection *conn) as a parameter, and call `Database_close` to clean it up 

* Change the code to accept parameters for MAX_DATA and MAX_ROWS, store them in the Database struct, and write that to the file, thus creating a database that can be arbitrarily sized.

* ??? 

* Add more operations you can do with the database, like find.

* ???

* Read about how C does it's struct packing, and then try to see why your file is the size it is. See if you can calculate a new size after adding more fields.

* ???

* Add some more fields to Address and make them searchable.

* ???

* Write a shell script that will do your testing automatically for you by running commands in the right order. Hint: Use set -e at the top of a bash to make it abort the whole script if any command has an error.

<details>

```
#!/bin/bash
set -e

make ex17
./ex17 db.dat c
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 2 frank frank@zedshaw.com
./ex17 db.dat s 3 joe joe@zedshaw.com
./ex17 db.dat l
./ex17 db.dat d 3
./ex17 db.dat l
./ex17 db.dat g 2
```
</details>

* Try reworking the program to use a single global for the database connection. How does this new version of the program compare to the other one?

* ???

* Go research stack data structure and write one in your favorite language, then try to do it in C.

* ???
