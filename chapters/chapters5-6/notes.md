
## Chapters 5-6


```
sizeof()
[]
&
*
->
.
```
<details>

```
sizeof()    // get the size of
[]          // array subscript
&           // the address of
*           // the value of
->          // structure dereference
.           // structure reference
```

</details>

<details>

```
auto        // give a local variable a local lifetime
extern      // declare an identifier is defined externally
goto        // jump to a label
long        // a long integer data type
register    // declare a variable be stored in a CPU register
short       // a short integer data type
signed      // a signed modifier for integer data types
sizeof      // determine the size of data
static      // preserve variable value after its scope exits
struct      // combine variables into a single record
typedef     // create a new type
union       // start a union-statement
unsighed    // an unsigned modifier for integer data types
volatile    // declare a data type may be modified elsewhere

```
</details>


If statement
<details>

```
if(TEST) {
CODE;
} else if(TEST) {
CODE;
} else {
CODE;
}
```
</details>


While statement -> continue; break
<details>

```
while(TEST) {
    CODE;
}

while(TEST) {
    if(OTHER_TEST) {
        continue;
    }
    CODE;
}

while(TEST) {
    if(OTHER_TEST) {
        break;
    }
    CODE;
}
```
</details>


do-while
<details>

```
do {
    CODE;
} while(TEST);
```
</details>


for-loop
<details>

```
for(INIT; TEST; POST) {
    CODE;
}
```
</details>


enum
<details>

```
// An enum creates a list of integer constants

enum { CONST1, CONST2, CONST3 } NAME;
```
</details>

Goto
<details>

```
// A Goto will jump to a label

if(ERROR_TEST) {
    goto fail;
}

fail:
    CODE;
```
</details>


function
<details>

```
TYPE NAME(ARG1, ARG2, ..) {
    CODE;
    return VALUE;
}

```
</details>


typedef
<details>

```
// a typedef defines a new type

typedef DEFINITION IDENTIFIER;

eg. `typedef unsigned char byte;'
```
</details>


struct
<details>

```
struct NAME {
    ELEMENTS;
} [VARIABLE_NAME];

typedef struct [STRUCT_NAME] {
    ELEMENTS;
} IDENTIFIER;
```

</details>

union
<details>

```
union NAME {
    ELEMENTS;
} [VARIABLE_NAME];
```

</details>
