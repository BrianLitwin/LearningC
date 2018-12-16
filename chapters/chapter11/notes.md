
## Chapter 11: Arrays and Strings

## Breaking It

* Get rid of the initializers that set up name.
Could break anything this way

* Accidentally set name[3] = 'A'; so that there's no terminator.
prints: `zeda*k?? or zeda(????` -> at `printf("%s\n", name);`

* Set the initializer to {'a','a','a','a'} so that there are too many 'a' characters and no space for the '\0' terminator.
same thing as above, printf("%s", ) messes up and prints something off at the end of the string

* Set the initializer to {'a','a','a','a'} so that there are too many 'a' characters and no space for the '\0' terminator.
you get a warning but nothing bad happens when you run it

## Extra Credit


!) Assign the characters into numbers, and then use printf to print them one character at a time. What kind of compiler warnings do you get?

* not really anything, it just prints out the number associated with the letter, eg 'a' - 97

2) Do the inverse for name, trying to treat it like an array of int and print it out one int at a time. What does the debugger think of that?

* nothing, you can exchange the numbers for letters and the letters for numbers

3) In how many other ways can you print this out?

* ???

4) If an array of characters is 4 bytes long, and an integer is 4 bytes long, then can you treat the whole name array like it's just an integer? How might you accomplish this crazy hack?

* ???

5) Take out a piece of paper and draw each of these arrays as a row of boxes. Then do the operations you just did on paper to see if you get them right.

* ???

6) Convert name to be in the style of another and see if the code keeps working.

* ??? 
