#include <stdio.h>
#include <stdlib.h>
#define TAB 8

int main(int argc, char *argv[]) {
  int c, i, x;
  int tab;
  x = 0;

  if (*++argv) {
    tab = atoi(*argv);
  } else {
    tab = TAB;
  }
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      x = 0;
      putchar(c);
    } else if (c != '\t') {
      putchar(c);
      x++;
    } else {
      for (i=0; i <= tab - x; i++) {
        putchar(' ');
      }
      x = 0;
    }
  }
}
