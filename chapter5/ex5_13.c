#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLINES 10
#define MAXLINES 100
#define MAXLEN 1000

char *lineptr[MAXLINES];

int getline1(char s[], int lim) {
  int c, i;

  for (i=0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines) {
  int nlines, len;
  char *p;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getline1(line, MAXLEN)) > 0) {
    if (nlines > MAXLINES || *p = malloc(len) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writetail(char *lineptr[], int lines) { 
  while (*++lineptr) {
    printf("%s\n", *lineptr);
  }
}

int main(int argc, char *argv[]) {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    writetail(lineptr, nlines);
    return 0;
  } else {
    printf("Input is too short to tail");
    return 1;
  }
}