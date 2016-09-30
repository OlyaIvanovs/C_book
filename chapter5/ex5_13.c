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
    if (nlines > MAXLINES || (p = malloc(len)) == NULL) {
      printf("Input is too long to tail");
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writetail(char *lineptr[], int exceptlines) { 
  int i;

  i = 0;

  while (*lineptr) {
    if (++i > exceptlines) {
      printf("%s\n", *lineptr);
    }
    lineptr++;
  }
}

int main(int argc, char *argv[]) {
  int nlines, taillines;

  taillines = 2;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    if (taillines > nlines) {
      taillines = 0;
    }
    writetail(lineptr, nlines - taillines);
    return 0;
  } else {
    printf("Input is too short to tail");
    return 1;
  }
}