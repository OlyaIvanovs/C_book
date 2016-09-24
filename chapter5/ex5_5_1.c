#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void strncpy1(char *s, char *t, int n) {
  int k = 0;
  while (*s++ = *t++) {
    ++k;
    if (k >= n) {
      return;
    }
  }
  if (k < n) {
    while (*++s = '\0');
  }
  return;
}

int main() {
  int n;
  char s[MAXLINE] = "mama myla ramu";
  char t[MAXLINE] = "kf";
  n = 4;

  // strncpy1(s, t, n);
  // printf("Result of my strncpy\n %s\n\n", s);
  strncpy(s, t, n);
  printf("Result of standart strncpy\n %s\n", s);
}