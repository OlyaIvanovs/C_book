#include <stdio.h>
#include <string.h>

#define MAXLINE 100


void reverse(char s[], int min_width) {
    int c, i, j, l;

    for (l=strlen(s); l < min_width; l++) {
      s[l] = ' ';
    }

    for ( i = 0, j = l-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s\n", s);
}


void itoa(int n, char s[], int min_width) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;

  do {
    s[i++] = (n % 10) + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s, min_width);
}

int main() {
  char string[MAXLINE];
  int n, min_width;

  n = -2111;
  min_width = 8; // minimum field width

  itoa(n, string, min_width);
}