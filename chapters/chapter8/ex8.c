#include <stdio.h>

int main(int argc, char *argv[]) {

  int i = 0;

  if (argc == 1) {
    printf("You didn't enter any arguments");

  } else if (argc >= 1 && argc <= 5) {
    printf("Here are your arguments: ");

    for (i = 1; i < argc; i++) {
      printf("%s ", argv[i]);
    }

  } else {
    printf("more than four arguments");
  }

  printf("\n");
  return 0;
}
