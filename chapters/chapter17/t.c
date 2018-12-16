#include <stdio.h>
#include <string.h>

int main() {
  int arr1[] = { 1,2,3 };
	int len = sizeof(arr1) / sizeof(int);
  int arr2[2];
  memcpy(arr2, arr1, len);

  int i;
  for (i = 0; i < len; i++) {
    printf("%2d:%2d\n", i, arr2[i]);
  }

  return 0;
}
