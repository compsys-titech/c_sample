#include <stdio.h>

int main() {
  char name[100];
  printf("What your name?: ");
  scanf("%s", name);
  printf("\n");
  printf("Hello world, %s!\n", name);
  return 0;
}
