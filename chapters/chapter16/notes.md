  what is a structure? 
  
  <details> 
  a group of one or more variables, possibly of different types, grouped together under a single name for convenient handling. 
  </details> 

  what does 'free' do?

  ```
  The malloc(), calloc(), valloc(), realloc(), and reallocf() functions allocate
     memory.  The allocated memory is aligned such that it can be used for any data
     type, including AltiVec- and SSE-related types.  The free() function frees allo-
     cations that were created via the preceding allocation functions.

     The free() function deallocates the memory allocation pointed to by ptr. If ptr
      is a NULL pointer, no operation is performed.
  ```

  create a pointer of type struct Person named `who` using malloc

  <details>
  ```
  struct Person *who = malloc(sizeof(struct Person));
  ```
  </details>

  describe malloc
  <details>
  I use malloc for memory allocate to ask the OS to give me a piece of raw memory.
  </details>

  what does the header file assert.h, string.h, and stdlib.h do?

  <details>

  ```
  The stdlib.h header defines four variable types, several macros,
  and various functions for performing general functions.
  ```

  ```
  The string.h header defines one variable type, one macro,
  and various functions for manipulating arrays of characters.
  ```

  ```
  The assert() macro tests the given expression and if it is false, the calling
     process is terminated.  A diagnostic message is written to stderr and the
     abort(3) function is called, effectively terminating the program.
  ```

  </details>

a struct called Person that contains a pointer of type char named `name`, and int types named age, weight, and height

<details>
```

struct Person {
  char *name;
  char age;
  char height;
  char weight;
};

```
</details>
what does strdup() do?
<details>
```
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1,
     does the copy, and returns a pointer to it.  The pointer may subsequently be used
     as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

     The strndup() function copies at most n characters from the string s1 always NUL
     terminating the copied string.
```
</details>


## How to Break It

1) Try passing NULL to Person_destroy see what it does. If it doesn't abort, then you must not have the -g option in your Makefile's CFLAGS.

```
person_Destroy(NULL);
```

2) Forget to call Person_destroy at the end, and then run it under the debugger to see it report that you forgot to free the memory. Figure out the options you need to pass to the debugger to get it to print how you leaked this memory.

* ???

3) Forget to free who->name in Person_destroy and compare the output. Again, use the right options to see how the debugger tells you exactly where you messed up.

* ???

4) This time, pass NULL to Person_print and see what the debugger thinks of that. You'll figure out that NULL is a quick way to crash your program.

```
if you don't have the assert to protect:
Segmentation fault: 11
```

## Extra Credit

In this part of the exercise, I want you to attempt something difficult for the extra credit: Convert this program to not use pointers and malloc. This will be hard, so you'll want to research the following:

How to create a struct on the stack just like you're making any other variable.
How to initialize it using the x.y (period) character instead of the x->y syntax.
How to pass a structure to other functions without using a pointer.

* ???
