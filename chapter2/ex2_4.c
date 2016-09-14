#include <stdio.h>

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = 0; s2[i] != '\0'; ++i) {
    for (k = j = 0; s1[k] != '\0'; ++k) {
      if (s1[k] != s2[i]) {
        s1[j++] = s1[k];
      } 
    }
    s1[j] = '\0';
    printf("%s\n", s1);
  }
  printf("%s", s1);
}

main() {
  char d[] = "aaaddddwwq";
  char d2[] = "pdccca";

  squeeze(d, d2);
}