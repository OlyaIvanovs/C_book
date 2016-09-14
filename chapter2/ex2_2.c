#include <stdio.h>
#define MAXLINE 1000
#define PRINT_FROM 10

int getline1(char s[], int lim) {
  int c, i;

  // for (i=0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; ++i) {
  //   s[i] = c;
  // }

  for (i=0; i < lim - 1; ++i) {
    if ((c=getchar())!= EOF) {
      if (c!='\n') {
        s[i] = c;
      }
    } else {
      break;
    }
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}


int main() {
  int len;
  int print_from;
  char line[MAXLINE];

  print_from = PRINT_FROM;

  while((len = getline1(line, MAXLINE)) > 0) {
    if (len > print_from) {
      printf("%s", line);
    }
  }
  return 0;
}