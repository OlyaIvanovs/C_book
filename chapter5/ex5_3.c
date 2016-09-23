#include <stdio.h>

#define MAXLINE 100

void strcat1(char *s, char *t) {
  while (*++s);
  while (*s++ = *t++);
}


int main() {
  char str1[MAXLINE] = "mama";
  char str2[MAXLINE] = "myla ramu";

  strcat1(str1, str2);
  printf("%s\n", str1);
}
