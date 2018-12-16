// print the characters in states

#include <stdio.h>


int main(int argc, char *argv[]) {
  char *states[] = {
    "arkansas", "north carolina", "virginia", "tennessee"
  };

  // get the size of the states array
  char *empty[] = { "" };
  int sizeOfStates = sizeof(states) / sizeof(empty);
  int i = 0;

  for (i=0;i<sizeOfStates;i++) {
    printf("%s\n", states[i]);

    int v = 0;
    int charC = sizeof(states[i]);

    for (v=0;v<charC;v++) {
      printf("%c \n", states[i][v]);
    }

  }


}
