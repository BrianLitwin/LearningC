## Chapter 3 


## Breaking it 

if you don't set a value ie `int age;`, what happens? 

<details> 

```
warning: variable 'age' is uninitialized when used here
[-Wuninitialized]
printf("You are %d yrs old and %d inches tall \n", age, height);
^~~
ex3.c:6:9: note: initialize the variable 'age' to silence this warning
int age; 
^
```
</details>


## Extra Credit - Questions 

1) Find as many other ways to break ex3.c as you can.
2) Run man 3 printf and read about the other % format characters you can use. These should look familiar if you used them in other languages (they come from printf).
3) Add ex3 the all list in your Makefile. Use this to make clean all and build all of your exercises thus far.
4) Add ex3 to your clean list in your``Makefile`` as well. Use make clean to remove it when you need to.

## Extra Credit - Solutions  

1) Find as many other ways to break ex3.c as you can.
<details></details> 

2a. What is an escape sequence? 
<details> 
https://en.wikipedia.org/wiki/Escape_sequences_in_C#Motivation

An escape sequence is a sequence of characters that does not represent itself when used inside a character or string literal, but is translated into another character or a sequence of characters that may be difficult or impossible to represent directly.
</details> 

2) What are the format specifiers/ sequences? 
<details> 
https://www.le.ac.uk/users/rjm1/cotter/page_30.htm
%c char single character
- %d (%i) int signed integer
- %e (%E) float or double exponential format
- %f float or double signed decimal
- %g (%G) float or double use %f or %e as required
- %o int unsigned octal value
- %p pointer address stored in pointer
- %s array of char sequence of characters
- %u int unsigned decimal
- %x (%X) int unsigned hex value
</details> 


3) Add ex3 the all list in your Makefile. Use this to make clean all and build all of your
exercises thus far.
<details> 

```
run:
make ../chapter1/ex1
make ex3
./ex3
```
</details> 

