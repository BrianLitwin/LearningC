
#import <stdio.h> 

int main(int argc, char *argv[]) {
	int distance = 100; 
	float power = 2.34f;
	float super_power = 56789.4532; 
	char initial = 'A';
	char first_name[] = "zed"; 
	char last_name[] = "shaw"; 

	printf("my name is %d", first_name);

	printf("my name is %s %c %s\n", first_name, initial, last_name);
	printf("I have %f superpowers\n", super_power); 
	printf("you are %d miles away\n", distance); 
	printf("you have %f power\n", power); 	

	int bugs = 10; 
	double bug_rate = 1.2; 
	long universe_of_defects = 1L * 1024L * 1024L; 
	double expected_bugs = bugs * bug_rate; 
	double part_of_universe = expected_bugs / universe_of_defects; 
	
	printf("you have %d bugs at an imaginary rate of %f\n", bugs, bug_rate); 
	printf("the entire universe has %ld bugs\n", universe_of_defects); 
	printf("you are expected to have %f bugs\n", expected_bugs); 
	printf("that is only %f part of the universe\n", part_of_universe); 	

    	char nul_byte = '\0';
    	int care_percentage = bugs * nul_byte;
    	printf("Which means you should care %d%%.\n", care_percentage); 

	return 0;		
}





