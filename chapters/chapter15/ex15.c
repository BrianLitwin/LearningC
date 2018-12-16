#include <stdio.h>

int main(int argc, char *argv[]) {

	int ages[] = { 2, 5, 10, 15, 20 };
	char *names[] = {
		"name1", "name2", "name3",
		"name4", "name5"
	};

  int i = 0;
	int count = sizeof(ages) / sizeof(int);
	int *cur_age = ages;
	char **cur_name = names;

	for (i = 0; i<count; i++) {
    printf("%s is %d yrs old \n", names[i], ages[i]);
  }

  printf("\n----\n");

  for (i=0;i<count;i++) {
    printf("%s is %d yrs old \n", *(cur_name + i), *(cur_age + i));
  }

  printf("\n----\n");

	for (i=0;i<count;i++) {
      printf("%s is %d yrs old \n", cur_name[i], cur_age[i]);
  }

  printf("\n----\n");

	for (cur_name = names, cur_age = ages;
		(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s is %d years old \n", *cur_name, *cur_age);
	}

	printf("\n----\n");

}
