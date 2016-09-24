#include <stdio.h>
#include <string.h>
#define MAXLINE 100

// concatenate at most n characters of string ct to string s , terminate s
// with '\0' ; return s .
char *my_strncat(char *s, char *t, int n) {
  int k = 0;

  while (*++s);
  while (*s++ = *t++) {
    k++;
    if (k >= n) {
      *s = '\0';
      return s;
    }
  }
  *s = '\0';
  return s;
}


int main() {
  int n;
  char s[MAXLINE] = "mama myla ramu";
  char t[MAXLINE] = "kf";
  n = 6;

  // my_strncat(s, t, n);
  // printf("Result of my strncat\n %s\n", s);
  strncat(s, t, n);
  printf("Result of standart strncat\n %s\n", s);
}