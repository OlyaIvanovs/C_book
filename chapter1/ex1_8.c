#include <stdio.h>

main() {
  int c;
  bool space_string;

  space_string = false;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      space_string = false;
    } 
    if ((c == ' ') && (space_string == false)) {
      putchar(c);
      space_string = true;
    }
  }
}