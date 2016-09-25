#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */\
char *alloc(int);


int getline1(char s[], int lim) {
  int c, i;

  for (i=0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void writelines(char lines[][MAXLEN], int nlines) {
  int i;

  while (nlines-- > 0) {
    printf("%s", lines[nlines]);
  }
}

int readlines2(char lines[][MAXLEN], int maxlines) {
  int len, nlines;

  nlines = 0;
  while((len = getline1(lines[nlines], MAXLEN)) > 0) {
    if (nlines >= maxlines) {
      return -1;
    } else {
      lines[nlines++][len] = '\0';
    }
  }
  return nlines;
}


int main() {
  int nlines;
  char lines[MAXLINES][MAXLEN];

  // if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
  if ((nlines = readlines2(lines, MAXLINES)) >= 0) {
    writelines(lines, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}


