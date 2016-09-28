#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */\
char *alloc(int);

int getline1(char *, int);
void writelines(char *lineptr[], int nlines);
void my_qsort(char *lineptr[], int left, int right);


int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline1(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = malloc(len)) == NULL) {
      return -1;
    } else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
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
    my_qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

void writelines(char *lineptr[], int nlines) {
  int i;

  while (nlines-- > 0) {
    printf("%s\n", *lineptr++);
  }
}

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

void my_qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) {
    return;
  }
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  my_qsort(v, left, last-1);
  my_qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}



