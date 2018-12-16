
print each state and then each character in each state

what is the expression:

```
for (exp1, exp2, exp3)
  statement
```

equivalent to?

<details>

```
exp1;
while (exp2) {
  statement
  exp3
}
```
</details>


```
for (i=0;i<4;i++) {
  printf("%s \n", states[i]);

  int z = 0;
  for(z=0;z<5;z++) {
    printf("%c \n", states[i][z]);
  }

}
```

## Breaking it

Take your favorite other language and use it to run this program, but include as many command line arguments as possible. See if you can bust it by giving it way too many arguments.

* ???

Initialize i to 0 and see what that does. Do you have to adjust argc as well, or does it just work? Why does 0-based indexing work here?

* ???

Set num_states wrong so that it's a higher value and see what it does.

*
```
//if you set it to 6 ->
arkansas
north carolina
virginia
tennessee

Segmentation fault: 11
```

## Extra Credit

Figure out what kind of code you can put into the parts of a for-loop.

* ???

Look up how to use the comma character (,) to separate multiple statements in the parts of the for-loop, but between the semicolon characters (;).

* The comma operator will always yield the last value in the comma separated list.

```
char *state = "";

for (i=0;state = states[i], i<4;i++) {
  printf("%s \n", state);
}
```

Read what a NULL is and try to use it in one of the elements from the states array to see what it'll print.

* ???

See if you can assign an element from the states array to the argv array before printing both. Try the inverse.

* could assign to states array but not to argv? 
