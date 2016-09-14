#include <stdio.h>
#include <limits.h>

main() {
  printf("maximum value of signed char %d\n", SCHAR_MAX);
  printf("minimum value of signed char %d\n", SCHAR_MIN);
  printf("maximum value of unsigned char %d\n", UCHAR_MAX);
  printf("maximum value of signed short %d\n", SHRT_MAX);
  printf("minimum value of signed short %d\n", SHRT_MIN);
  printf("maximum value of unsigned short %d\n", USHRT_MAX);
  printf("maximum value of signed int %d\n", INT_MAX);
  printf("minimum value of signed int %d\n", INT_MAX);
  printf("maximum value of unsigned int %d\n", UINT_MAX);
  printf("maximum value of signed long %ld\n", LONG_MAX);
  printf("minimum value of signed long %ld\n", LONG_MIN);
  printf("maximum value of unsigned long %ld\n", ULONG_MAX);
} 