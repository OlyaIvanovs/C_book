#include <stdio.h>
#define MAXLINE 100

int strend(char *s, char *t) {
  int n, k;

  while (*++s);
  while (*++t) {
    ++n;
  };

  for (k=0 ; *s == *t; --s, --t, ++k) {
    if (k == n) {
      return 1;
    }
  }
    
  return 0;
}

int main() {
  int res;
  char str1[MAXLINE] = "ma";
  char str2[MAXLINE] = "myla ramu mama";

  res = strend(str2, str1);
  printf("%s\n", str2);
  printf("%d\n", res);
}