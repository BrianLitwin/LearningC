## Chapter 1

## Notes 

What is a .h file? 
<details>

Header files serve two purposes.
- System header files declare the interfaces to parts of the operating system. You include them in your program to supply the definitions and declarations you need to invoke system calls and libraries.
- Your own header files contain declarations for interfaces between the source files of your program. Each time you have a group of related declarations and macro definitions all or most of which are needed in several different source files, it is a good idea to create a header file for them.

https://www.tutorialspoint.com/cprogramming/c_header_files.htm

</details>

What is '#include'? 
<details>

You request the use of a header file in your program by including it, with the C preprocessing directive ‘#include’.

https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html#Header-Files
</details>

How do you find out more about something like stdio.h? 
<details> 

`man stdio`
</details> 

What is stdio.h ?
<details> 

standard input/output library functions
</details> 

What is the 'main' function? 
<details>

the main function is "called" by the operating system when the user runs the program. Thus the main function is always the first code executed when a program starts.

https://en.cppreference.com/w/cpp/language/main_function
</details>

What are main()'s arguments? 
<details>

- For the function to be totally complete it needs to return an int
and take two parameters: an int for the argument count and an array of char * strings
for the arguments. 
- `int main(int argc, char *argv[])`
- argc    : Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.
0 argv    :  Pointer to the first element of an array of pointers to null-terminated multibyte strings that represent the arguments passed to the program from the execution environment (argv[0] through argv[argc-1]). The value of argv[argc] is guaranteed to be a null pointer.
</details>

what is printf? 
<details>

The C library function `int printf(const char *format, ...)` sends formatted output to stdout.
https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

We use `printf()` function with `%d` format specifier to display the value of an integer variable.
Similarly %c is used to display character, %f for float variable, %s for string variable, %lf for double and %x for hexadecimal variable.
To generate a newline,we use “\n” in C printf() statement.
https://fresh2refresh.com/c-programming/c-printf-and-scanf/
</details>

what is the syntax for declaring a function
<details>
```
TYPE NAME(ARG1, ARG2, . . ) {
CODE;
return VALUE;
}
```
</details>

How do you run the example program in this chapter? 
<details> 

-> make ex1
-> ./ex1 
</details> 

What does `int distance = 100` mean in english? 
<details> 

assign 100 to the distance integer 
</details> `

## Exercise 

print hello world - Extra Credit and Breaking it are covered in subsequence exercises 


## Breaking it 

what warning do you get if you leave out printf arguments? 
- eg `printf("you are %d miles away\n");`
<details> 

```
ex1.c:11:19: warning: more '%' conversions than data arguments [-Wformat]
printf("you are %d miles away\n"); 
```
</details> 

```
1. 
ex1_ec.c:7:7: warning: incompatible pointer to integer conversion initializing 'char' with an expression of type
'char [2]' [-Wint-conversion]
char cha = "A";


2.  
error: array initializer must be an initializer list or string literal
char str[5] = 'fiver';
^

3. 
initializer-string for char array is too long
char str[5] = "fiverr";
^~~~~~~~

4. 
// char str[5] = "fiver"; 
// prints -> 
// fiverA?h??i??? 

```




