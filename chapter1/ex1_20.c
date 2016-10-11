#include <stdio.h>
#define TAB 8

int main() {
  int c, i, x;

  x = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      x = 0;
      putchar(c);
    } else if (c != '\t') {
      putchar(c);
      x++;
    } else {
      for (i=0; i <= TAB - x; i++) {
        putchar(' ');
      }
      x = 0;
    }
  }
}
