#include <stdio.h>

int main() {
  int n; //number of different characters;
  int i, c, k, f;
  int new_char;

  n = 0;

  int characters[1000];
  int count_characters[1000];

  while ((c = getchar()) != EOF) {
    if (n == 0) {
      characters[n] = c;
      count_characters[n] = 1;
      n = n + 1;
    } else {
      for (i = 0; i < n; i++) {
        if (c == characters[i]) {
          ++count_characters[i];
          // printf("%d", count_characters[i]);
        } else {
          n = n + 1;
          characters[n] = c;
          count_characters[n] = 1;
          // cont?inue;
        }
      }
    }
  } 
  for (k = 0; k < n; ++k) {
    putchar(characters[k]);
    printf("%d\n", count_characters[k]);
  }
}
