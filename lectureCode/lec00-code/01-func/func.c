int func0(int x, int y) {
  int max = x;
  if ( y > max ) max = y;
  return max;
}

int func1(int x, int y) {
  int max = x > y ? x : y;
  return max;
} 

int func2(int x, int y) {
  return x > y ? x : y;
}

float func3(float x, float y) {
  return x > y ? x : y;
}
