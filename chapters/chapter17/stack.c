#include <stdio.h>

#define max_item_count 100

struct Item_container {
  int len;
  int items[max_item_count];
};

int Pop_last(struct Item_container *con) {
  int it = con->items[con->len - 1;];
  con->len = con->len - 1;
  con->items[len] = [con->items[max_item_count - 1]]
  return it
}

int main(int argc, char *argv[])
{
  int items_init[] = { 1, 12, 13, 14, 15 };
  struct Item_container *con = malloc(sizeof(Item_container));
  con->items = items_init
  con->len = sizeof(items_init)
  printf("%d\n", popLast());
  return 0;
}
