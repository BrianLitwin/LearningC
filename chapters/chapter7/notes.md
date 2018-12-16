
## Chapter 7 Types and Variables 

* break printf by passing in the wrong arguments 

## Understanding: 

  1) create makefile
  2)

    assign 100 to an integer named distance
    assign 2.45f to a float named power
    assign 56789.4532 to a float named super_power
    assign the letter A to a char called initial
    assign Zed to an array of chars called first_name
    assigned "Shaw" to an array of chars called last_name

    print ->
    you are _ miles away
    you have _ levels of power
    you _ awesome super powers
    my whole name is _ _ _

    assign 100 to an int named bugs
    assign 1.2 to a double named bug_rate
    assign 1L * 1024L * 1024L * 1024L to a long named universe_of_defects
    assign a double named expected_bugs to bugs x bug rate
    assign a double called part_of_universe to expected bugs / universe_of_defects

    print ->
    you have _ bugs at the imaginary rate of _
    the entire universe has _ bugs (use universe of defects long)
    you are expected to have _ bugs (use expected bugs)
    that is only _ portion of the universe (use part_of_universe)

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    printf("Which means you should care %d%%.\n", care_percentage);

  3) run it
  4) go through it with debugger
  5) remove the bad code and automate/test the output
  6) run it in the debugger w/ the wrong arguments in printf and see what it says 

tried: `printf("my name is &d", first_name); `
printed: `my name is -272631569`


```
Undefined symbols for architecture x86_64:
  "_print", referenced from:
      _main in ex7-3a9aa3.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [ex7] Error 1
```

Extra Credit 
1) Make the number you assign to universe_of_defects various sizes until you get a warning from the compiler.
2) What do these really huge numbers actually print out?
3) Change long to unsigned long and try to find the number that makes it too big.
4) Go search online to find out what unsigned does.
5) Try to explain to yourself (before I do in the next exercise) why you can multiply a char and an int.
