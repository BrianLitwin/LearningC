
What are the four example ways he gives to print arrays?
<details>

1) regular index eg ` names[i] `
2) `*(cur_name + i)`
3) create a pointer and increment it same as 1, eg ` cur_name[i] ` (cur name is a pointer?)
4) he says this is bad:
```
for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }
```

type cast two ints to a double called mean after, after dividing them
<details>
#include <stdio.h>
```
int main() {
int sum = 17, count = 5;
double mean;
mean = (double) sum / count;
printf("mean: %f", mean);
return 0;   
}
```
</details>

</details>
Say the following in English
<br>
`type *ptr`
<details>
a pointer of type named ptr
</details>
`*ptr`
<details>
the value of w/e ptr is pointed at
</details>
`*(ptr + i)`
<details>
the value of whatever ptr is pointed at plus i
</details>
`&thing`
<details>
the address of thing
</details>
`type *ptr = &thing`
<details>
A pointer of type named ptr set to the address of thing
</details>
`ptr++`
<details>
`Increment where ptr points`
</details>


## How to Break It

You can break this program by simply pointing the pointers at the wrong things:

1) Try to make cur_age point at names. You'll need to use a C cast to force it, so go look that up and try to figure it out.

* ???

```
int *cur_age = (int) names[0];
```

2) In the final for-loop, try getting the math wrong in weird ways.

* ???

3) Try rewriting the loops so that they start at the end of the arrays and go to the beginning. This is harder than it looks.

```
for (i = count - 1; i >= 0; i--)

for (cur_name = names + count - 1, cur_age = ages + count - 1;
  (cur_age - ages) >= 0; cur_name--, cur_age--)
```

## Extra Credit
1) Rewrite all of the arrays in this program as pointers.

* `int *ages = (int[5]) { 2, 5, 10, 15, 20 };` ?

2) Rewrite all of the pointers as arrays.

* ???

3) Go back to some of the other programs that use arrays and try to use pointers instead.

* ???

4) Process command line arguments using just pointers similar to how you did names in this one.

* ???

5) Play with combinations of getting the value of and the address of things.

* ???

6) Add another for-loop at the end that prints out the addresses that these pointers are using. You'll need the %p format for printf.
```
for (i=0;i<count;i++) {
printf("%p \n", &cur_age[i]);
}
```

7) Rewrite this program to use a function for each of the ways you're printing out things. Try to pass pointers to these functions so that they work on the data. Remember you can declare a function to accept a pointer, but just use it like an array.

```
void print_ptrs(char *chars[], int count) {
    int i = 0;
    for (i=0;i<count;i++) {
        printf("%s \n", chars[i]);
    }
}
```

8) Change the for-loops to while-loops and see what works better for which kind of pointer usage.

* ???
