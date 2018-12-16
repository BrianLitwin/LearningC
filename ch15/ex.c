#include <stdio.h>
int main() {
  int ages[] = { 1, 2, 3, 4, 5 };
  char *names[] = {
    "one", "two", "three", "four", "five"
  };

  int count = sizeof(ages) / sizeof(int);
  int i;

  for (i = 0; i < count; i++) {
    printf("%d: %s\n", ages[i], names[i]);
  }

  printf(" -- \n");

  int *cur_age = ages;
  char **cur_name = names;

  for (i = 0; i < count; i++) {
    printf("%d: %s\n", *(cur_age + i), *(cur_name + i));
  }

  printf(" -- \n");

  for (i = 0; i < count; i++) {
    printf("%d: %s\n", cur_age[i], cur_name[i]);
  }

  printf(" -- \n");

  for (cur_age = ages, cur_name = names; cur_age - ages < count; cur_age++, cur_name++) {
      printf("%d: %s\n", *cur_age, *cur_name);
  }


  return 0;
}
