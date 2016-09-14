#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000000

void expand(char s1[]) {
  char s2[MAXLINE];
  int i, j;

  for(i=j=0; s1[i]!='\0'; ++i) {
    if (isalnum(s1[i]) && isalnum(s1[i+2]) && (s1[i+2] > s1[i]) && s1[i+1] == '-') {
      s2[j] = s1[i];
      printf("%c", s2[j]);
      while ((s1[i+2]- s2[j]) != 0) {
        s2[j] = s2[j] + 1;
        printf("%c", s2[j]);
      }
      i = i + 2;
    } else {
      printf("%c", s1[i]);
    }
  }

}

main() {
  char string1[] = "a-b-d-f";

  expand(string1);
}