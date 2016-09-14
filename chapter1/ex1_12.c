#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int c;
  int state;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        state = OUT;
        putchar('\n');
      }
    } else {
      state = IN;
      putchar(c);
    }
  }
}