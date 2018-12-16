
What is <ctype.h>?
<details>
from `man ctype`:
The above functions perform character tests and conversions on the inte-
     ger c.  They are available as macros, defined in the include file
     <ctype.h>, or as true functions in the C library.


</details>

what are forward declarations?
<details>
Tell C that you'll be using some functions later in your program without actually having to define them.
</details>

## How to break it

1) Remove the forward declarations to confuse the compiler and cause it to complains about can_print_it and print_letters.
* ???


2) When you call print_arguments inside main, try adding 1 to argc so that it goes past the end of the argv array.
* Thought I would get a segfault, but nothing happened

## Extra credit
1) Rework these functions so that you have fewer functions. For example, do you really need can_print_it?
* not super interesting

2) Have print_arguments figure out how long each argument string is by using the strlen function, and then pass that length to print_letters. Then, rewrite print_letters so it only processes this fixed length and doesn't rely on the '\0' terminator. You'll need the #include <string.h> for this.
* update the function signature in the forward declaration/function
*

3) Use man to look up information on isalpha and isblank. Use other similar functions to print out only digits or other characters.

* look at them; lookup `man string` and `man ctype`

4) Go read about how other people like to format their functions. Never use the K&R syntax (it's antiquated and confusing) but understand what it's doing in case you run into someone who likes it.

* ??? 
