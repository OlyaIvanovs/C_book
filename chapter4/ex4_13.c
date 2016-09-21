#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j) {
  int c = s[i];

  s[i++] = s[j];
  s[j--] = c;

  if (i <= j) {
    reverse(s, i, j);
  }
}

int main() {
  char s[] = "abcd";

  reverse(s, 0, strlen(s) - 1);
  printf("%s", s);
}
