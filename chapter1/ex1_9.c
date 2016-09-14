#include <stdio.h>

int main() {
  int c;
  int space_string;

  space_string = 1;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      space_string = 0;
    } 
    if ((c == ' ') && (space_string == 0)) {
      putchar(c);
      space_string = 1;
    }
  }
}