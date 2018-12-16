
#include <stdio.h> 


int main(int argc, char *argv[]) {
	
	int i = 0; 
		
	for (i=0;argv[1][i] != '\0';i++) {
		int letter = argv[1][i];
		int uppercase = argv[1][i] -  32; 
		printf("%d : %c \n", letter, letter); 
		printf("uppercase :  %c", uppercase);
		printf("\n");  
	
	}	

}




