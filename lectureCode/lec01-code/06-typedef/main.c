#include <stdio.h>

typedef
   struct {
      float length;
      float width;
      char  name[19];
   }
  Rect;

int main(int argc, char *argv[]) {

  Rect rectangle_big = {10, 20, "big"};

  Rect rectangle_small = {1, 2, "small"};

  printf("Rectangle %s is %f x %f\n", 
	 rectangle_big.name,
	 rectangle_big.length,
	 rectangle_big.width);

  printf("Rectangle %s is %f x %f\n", 
	 rectangle_small.name,
	 rectangle_small.length,
	 rectangle_small.width);

  rectangle_small = rectangle_big;

  printf("Rectangle %s is %f x %f\n", 
	 rectangle_small.name,
  	 rectangle_small.length,
  	 rectangle_small.width);

  return 0;

}
