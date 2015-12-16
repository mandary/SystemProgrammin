#include <stdio.h>

int main(int argc, char **argv) {
  int arr[3] = {1, 2, 3};
  int *int_ptr = &arr[0];
  char *char_ptr = (char *) int_ptr;

  printf("int_ptr: %p; *int_ptr: %d\n", int_ptr, *int_ptr);
  
  int_ptr += 1;
  printf("int_ptr: %p; *int_ptr: %d\n", int_ptr, *int_ptr);

  int_ptr += 2; // uh oh
  printf("int_ptr: %p; *int_ptr: %d\n", int_ptr, *int_ptr);

  printf("char_ptr: %p; *char_ptr: %d\n", char_ptr, *char_ptr);

  char_ptr += 1;
  printf("char_ptr: %p; *char_ptr: %d\n", char_ptr, *char_ptr);

  char_ptr += 2;
  printf("char_ptr: %p; *char_ptr: %d\n", char_ptr, *char_ptr);

  for (char_ptr = (char *)&arr[0]; char_ptr < (char *)&arr[3]; char_ptr++ ) {
    printf("%d", *char_ptr);
  }
  printf("\n");

  return 0;
}
