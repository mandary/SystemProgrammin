#include <stdio.h>

typedef
   struct {
      float length;
      float width;
      char  name[19];
   }
  Rect;

int main(int argc, char *argv[]) {

  int array[100];
  int* pInt = array;

  Rect rectangle_small;

  printf("An int is %lu bytes\n",
	 sizeof(int));

  printf("A float is %lu bytes\n",
	 sizeof(float));
  printf("A double is %lu bytes\n",
	 sizeof(double));
  printf("A Rect is %lu bytes\n",
	 sizeof(Rect));

  printf("rectangle_small is %lu bytes\n",
	 sizeof(rectangle_small));

  printf("rectangle_small.name is %lu bytes\n",
	 sizeof(rectangle_small.name));

  printf("array is %lu bytes\n",
	 sizeof(array));

  printf("pInt is %lu bytes\n",
	 sizeof(pInt));

  printf("*pInt is %lu bytes\n",
	 sizeof(*pInt));

  return 0;

}
