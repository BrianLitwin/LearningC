
#include <stdio.h>

int main(int argc, char *argv[]) {

	int i;
	char letter;

	int a;

	for (a = 1; a <= argc; a++) {
		printf("Starting Loop: ");

		for (i=0; letter = argv[a][i], argv[a][i] != '\0'; i++) {

			switch (letter) {
				case 'a':
				case 'A':
					printf("%c \n", letter);
				break;

			case 'i':
			case 'I':
				printf("%c \n", letter);
				break;

			default:
				printf("%d: %c is not a vowel \n", i, letter);
		}
	}
}

	return 0;

}
