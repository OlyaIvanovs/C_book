#include <stdio.h>
#include <ctype.h>
#include "calc.h"


/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isalnum(c) && c != '.' && c != '-') {
    return c;
  }

  i = 0;

  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    return MATH;
  }

  if (c == '-') {
    if (!isdigit(c = getch())) {
      return '-';
    } else {
      s[++i] = c;
    }
  }
  
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}