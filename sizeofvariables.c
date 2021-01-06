#include<stdio.h>

int main()
{
  int a = 545;
  float b = 1.2;
  double c = 3.1415926;
  char d = 'a';
  unsigned int e = 101;
  unsigned long f = 11;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("float b value: %f and size: %lu bytes\n", b, sizeof(b));
  printf("double c value: %f and size: %lu bytes\n", c, sizeof(c));
  printf("char d value: %c and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("unsigned long f value: %lu and size: %lu bytes\n", f, sizeof(f));
}

