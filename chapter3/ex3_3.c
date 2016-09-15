#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000000

int is_alnum(char a, char b) {
  if ((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') \
    || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z') \
    || (a >= '0' && a <= '9' && b >= '0' && b <= '9')) {
    return 1;
  } else {
    return 0;
  }
}

void expand(char s1[]) {
  char s2[MAXLINE];
  int i, j, f;

  for(i=j=0; s1[i]!='\0'; ++i) {
    if (s1[i] == '-' && is_alnum(s1[i+1], s1[i-1]) && (s1[i+1] > s1[i-1])) {
      s2[++j] = s1[i-1] + 1;
      printf("%c", s2[j]);
      f = s2[j];
      while ((s1[i+1]- f) != 0) {
        ++f;
        s2[++j] = f;
        printf("%c", s2[j]);
      }
      ++i;
    } else if (is_alnum(s1[i], s1[i+2]) && (s1[i+2] > s1[i]) && s1[i+1] == '-') {
      s2[j] = s1[i];
      printf("%c", s2[j]);
      f = s2[j];
      while ((s1[i+2]- f) != 0) {
        ++f;
        s2[++j] = f;
        printf("%c", s2[j]);
      }
      i = i + 2;
    } else {
      printf("%c", s1[i]);
      s2[j++] = s1[i];
    }
  }
  printf("\n%s", s2);
}

main() {
  char string1[] = "b-w";
  char string2[] = "2-7";
  char string3[] = "a-b-c-f";
  char string4[] = "-a-b-c9-0-3b-s-";
  char string5[] = "a-0-6b--pq-w9-0-3";
  char string6[] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
  char string7[] = "5-w";
  expand(string6);
}