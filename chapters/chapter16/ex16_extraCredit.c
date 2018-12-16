#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int weight;
  int height;
};

struct Person person_Create(char *name, int age, int weight, int height) {
  struct Person who;
  who.name = strdup(name);
  who.age = age;
  who.weight = weight;
  who.height = height;
  return who;
}

void person_Destroy(struct Person *who) {
  assert(who != NULL);
  free(who->name);
  free(who);
}

void person_Print(struct Person who) {
  printf("name: %s\n", who.name);
  printf("\tage: %d\n", who.age);
  printf("\tweight: %d\n", who.weight);
  printf("\theight: %d\n", who.height);
}

void person_printMemoryAddress(struct Person *who) {
  printf("memory address - %s: %p \n", who->name, who);
}

int main(int argc, char *argv[]) {
  struct Person joe = person_Create("joe", 4, 5, 6);
  struct Person sal = person_Create("sal", 1, 2, 3);

  //person_printMemoryAddress(joe);
  person_Print(joe);

  //person_printMemoryAddress(s);
  person_Print(sal);

  joe.age = 10;
  sal.weight = 108;
  person_Print(joe);
  person_Print(sal);
}
