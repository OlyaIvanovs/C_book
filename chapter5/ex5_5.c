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
}

// void strncat1(char *s, char *t, int n) {}

// void strncmp1(char *s, char *t, int n) {}


int main() {
  int n;
  char s[MAXLINE] = "mama myla ramu";
  char t[MAXLINE] = "kk";
  n = 4;

  strncpy1(s, t, n);
  // strncpy(s, t, n);
  printf("Result of strncpy %s", s);

  // strncat1(s, t, n);
  // strncmp1(s, t, n);
}