
#include <stdio.h>
#include <ctype.h>

char lower(char letter);

int main() {

    char c = 'e';
    char lowercase = tolower(c);
    printf("%c \n", lowercase);
    printf("%c \n", lower('A'));
    return 0;
}

char lower(char letter) {
  return tolower(letter);
}
