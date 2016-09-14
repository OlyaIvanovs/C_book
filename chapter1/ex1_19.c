#include <stdio.h>
#define MAXLINE 1000

int getline1(char s[], int lim) {
  int c, i;

  for (i=0; i < lim - 1 && (c=getchar()) != EOF && c!='\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void reverse(char to[], char from[], int len) {
  int i;
  i = 0;
  while ((to[i] = from[len-1-i]) != '\0') {
    ++i;
  }
  to[i] = '\0';
}

int main() {
  int len, len_copy;
  char line[MAXLINE];
  char reverse_line[MAXLINE];

  while((len = getline1(line, MAXLINE)) > 0) {
    len_copy = len;
    reverse(reverse_line, line, len);
  }

  if (len_copy > 0) {
    printf("%s\n", reverse_line);
  }
}