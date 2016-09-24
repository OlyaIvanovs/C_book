#include <stdio.h>

#define MAXLINE 100

void strcat1(char *s, char *t) {
  while (*++s);
   while (*s++ = *t++);
  printf("%s\n", s);
}


int main() {
  char str1[MAXLINE] = "mama";
  char str2[MAXLINE] = "myla";

  strcat1(str1, str2);
  printf("%s\n", str1);
}
