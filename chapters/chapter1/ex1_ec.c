
// add some more output

#include <stdio.h>

int main(int argc, char *argv[]) {
	int distance = 100;
	double dbl = 1.248392;
	char ch = 'A';
	char str[5] = "fiver";

	printf("this is a double: %lf  \n", dbl);
	printf("an int: %d\n", distance);
	printf("a character: %c\n", ch);
	printf("finally, another line of text\n");
	printf("a character array? %s \n", str);

	return 0;
}
