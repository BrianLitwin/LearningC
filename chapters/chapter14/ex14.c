#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_letters(char arg[], int strlength);
int can_print(char c);

void print_arguments(int argc, char *argv[]) {
  int i = 0;

  for (i=0;i<argc;i++) {
    int l = strlen(argv[i]);
    print_letters(argv[i], l);
  }
}

void print_letters(char arg[], int strlength) {
  int i = 0;

  for (i=0; i <= strlength; i++) {
      char c = arg[i];
      if (can_print(c)) {
        printf("%c = %d \n", c, c);
    }
  }
  printf("\n");
}

int can_print(char c) {
  return (isalpha(c) || isblank(c));
}

int main(int argc, char *argv[]) {
  print_arguments(argc, argv);
  return 0;
}
