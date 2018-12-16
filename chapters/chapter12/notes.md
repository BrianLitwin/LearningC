
## How to break it

Get rid of the '\0' at the end of full_name and re-run it. Run it under the debugger, too. Now, move the definition of full_name to the top of main before areas. Try running it under the debugger a few times and see if you get some new errors. In some cases, you might still get lucky and not catch any errors.

* ???

Change it so that instead of areas[0] you try to print areas[10]. See what the debugger thinks of that.

* It printed out a random huge number: `1684922389`

Try other ways to break it like this, doing it to name and full_name too.

## Extra Credit

1) Try assigning to elements in the areas array with areas[0] = 100; and similar.

* prints rando numbers: `32766 -272631504`

2) Try assigning to elements of name and full_name.

* not super hard? Make sure they are in array bounds?

3) Try setting one element of areas to a character from name.

*  `areas[0] = name[2];` will print 100 b/c `e` is an integer

4) Search online for the different sizes used for integers on different CPUs.

* ???
