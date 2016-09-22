#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c, sign, temp;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    temp = c;
    c = getch();
    if (!isdigit(c)) {
      ungetch(temp);
      ungetch(c);
      return 0;
    }
  }


  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  *pn *= sign;

  if (c != EOF)
    ungetch(c);
  return c;
}

int getch(void) /* get a (possibly pushed-back) character */
{
 return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
/* push character back on input */
{
  if (bufp >= BUFSIZE)
  printf("ungetch: too many characters\n");
  else
  buf[bufp++] = c;
}



int main() {
  int x, retval;

  retval = getint(&x);
  printf("retval = %d, x = %d\n", retval, x);
}