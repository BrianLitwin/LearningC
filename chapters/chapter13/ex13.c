#include <stdio.h>

int main(int argc, char *argv[]) {
  argv[0] = states[0];
  states[1] = argv[1];

  int i = 0;
  for (i=1;i<argc;i++) {
    printf("%s \n", argv[i]);
  }

  i = 0;

  char *states[] = {
    "arkansas", "north carolina", "virginia", "tennessee"
  };

  char *state = "";

  for (i=0;state = states[i], i<4;i++) {
    printf("%s \n", state);
  }
}
