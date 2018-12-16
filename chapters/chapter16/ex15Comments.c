
/*
Create a struct called Person. Create a function to create a Person,
to free Person's memory, and
to print Person's attributes. Make two people and print
them. Print their memory locations. Then change some of their attributes and print
them again. Then free the memory allocated to those two People.
*/

// include access to the stdio header file for printf
#include <stdio.h>

// ask for assert()
#include <assert.h>

// ask for mallc()
#include <stdlib.h>

// ask for stdrup()
#include <string.h>

// create a struct called Person that
// has four properties, including a pointer
// of type char named `name`.
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// define a function that returns a type `struct Person`
struct Person *Person_create(char *name, int age, int height,
        int weight)
{

    // make a pointer of type `struct Person` called `who`
    // asks the OS for a piece of raw memory using malloc
    // pass to malloc the size of the struct Person
    struct Person *who = malloc(sizeof(struct Person));

    // test that who does not = NULL
    // if f, terminate
    assert(who != NULL);

    // allocate sufficient memory for the value of name
    // and return a pointer to it
    who->name = strdup(name);

    // assign age, height, and weight patameters
    // to their respective properties in Person
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

// function that deallocates the memory assigned to Person
void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    // deallocate the memory pointed to by name
    free(who->name);

    // deallocate the memory allocated in the creation
    // of the Person struct
    free(who);
}

// print the values associated with the Person struct
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
