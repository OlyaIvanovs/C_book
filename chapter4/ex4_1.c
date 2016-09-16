#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strindex(char s[], char t) {
  int i;

  for (i = strlen(s)-1; i>0; i--) {
    if (s[i] == t) {
      return i;
    }
  }
  return -1;
}


int main() {
  char t, pos;

  char s[] = "MAMA MAMA MAMAM";
  t = 'A';

  pos = strindex(s, t);

  if (pos > 0) {
    printf("the rightmost occurrence of %c in string %d\n", t, pos);
  }
}