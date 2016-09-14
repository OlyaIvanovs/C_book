#include <stdio.h>

int any(char s1[], char s2[]) {
  int i, k;

  for (i=0; s2[i] != '\0'; i++) {
    for (k=0; s1[k] != '\0'; k++) {
      if (s2[i] == s1[k]) {
        return k;
      } 
    }
  }
  return -1;
}

main() {
  char s1[] = "aaddderr";
  char s2[] = "mmmmmjadhkjgs d";

  int pos;

  pos = any(s1, s2);
  printf("the first location in a string s1 where any character from the string s2 occurs  ----- %d\n", pos);
}