#include <stdio.h>

main() {
  float fahr, celcius;
  float upper, lower, step;

  lower = 0;
  step = 5;
  upper = 50;

  printf("%s\t%s\n\n","celcius", "fahr");
  celcius = lower;
  while (celcius <= upper) {
    fahr = 9.0/5.0*celcius + 32.0;
    printf("%3.0f\t%8.1f\n", celcius, fahr);
    celcius = celcius + step;
  }
}