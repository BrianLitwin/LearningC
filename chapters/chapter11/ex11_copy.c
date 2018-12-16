#include <stdio.h>

int main(int argc, char *argv[]) {
	int numbers[4] = { 'a'};
	char name[4] = { 97, 97, 97 };
 	printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%c %c %c %c\n", name[0], name[1], name[2], name[3]);
	printf("%s\n", name);

	numbers[0] = 'a';

	name[0] = 'z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = 'a';

  printf("%d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%c %c %c %c\n", name[0], name[1], name[2], name[3]);
	printf("%s\n", name);

  char *another = "zed";
  printf("%s\n", another);
  printf("%c %c %c %c\n", another[0], another[1], another[2], another[3]);
  return 0;
}
