#include <stdio.h>
#include <string.h>

#define MAXLINE 100


// convert an integer into a string by calling a recursive routine.
void itoa(int n, char s[], int i, int minus) {
  
  i = i + 1;
  if (n / 10) {
    itoa(n / 10, s, i, minus);  
  } else if (minus){
    i = i + 1;
    s[i] = '-';
    i = i - 1;
  }

  s[i] = n % 10 +'0';
}

void reverse(char s[]) {
  int c, i, j, len;

  len = strlen(s);
  for (i=0, j=len - 1; i <=j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main() {
  int i, num, minus;
  char s[MAXLINE];
  
  i = -1; 
  num = -2045;

  // for negative numbers
  if (num < 0) {
    num = -num;
    minus = 1;
  }

  itoa(num, s, i, minus);
  reverse(s);
  printf("%s\n", s);
}