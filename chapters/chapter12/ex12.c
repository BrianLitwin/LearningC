// request the system header file stdio
// gives you access to standard library in/out functions


/*

{ areas } make an array of type int that is initialized to { 10, 12, 13, 14, 20 }
{ name } make an array of type char that is initialized to { 'z', 'e', 'd' }
{ full_name } make an array of type char that is initialized to Zed A. Shaw as a series of array elements

print the size of an int
print the size of areas
print the number of ints in areas
print the size of the first two items in areas

print the size of a char
print the size of name
print the number of chars

print the size of full name
print the number of chars in full_name
print name and full name

*/
#include <stdio.h>

int main(int argc, char *argv[]) {
  int areas[] = { 10, 12, 13, 14, 20 };
  char name[] = { 'z', 'e', 'd', '\0' };
  char full_name[] = {
    'z', 'e', 'd',
    ' ', 'A', '.', ' ',
    's', 'h', 'a', 'w', '\0'
  };

  full_name[5] = 'x';
  name[0] = 'x';

  printf("%ld \n", sizeof(int));
  printf("%ld \n", sizeof(areas));
  printf("%ld \n", sizeof(areas) / sizeof(int));
  printf("%d %d\n", areas[0], areas[1]);

  printf("%ld \n", sizeof(char));
  printf("%ld \n", sizeof(name));
  printf("%ld \n", sizeof(name) / sizeof(char));

  printf("%ld \n", sizeof(full_name));
  printf("%ld \n", sizeof(full_name) / sizeof(char));
  printf("%s %s \n", name, full_name);

}
