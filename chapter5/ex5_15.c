#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort1(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);

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

int strcmp1(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') {
      return -1;
    }
  }
  return *s - *t;
}

int strcmp_f(char *s, char *t) {
  printf("foldcase\n");
  printf("%c\n", tolower(*s));
  for (; tolower(*s) == tolower(*t); s++, t++) {
    if (*s == '\0') {
      return -1;
    }
  }
  return tolower(*s) - tolower(*t);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2) {
    return -1;
  } else if (v1 > v2) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int foldcase = 0;


  while (*argv) {
    if (strcmp(*argv, "-n") == 0) {
      numeric = 1;
    } else if (strcmp(*argv, "-r") == 0) {
      reverse = 1;
    } else if (strcmp(*argv, "-f") == 0) {
      foldcase = 1;
    }
    argv++;
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort1((void**) lineptr, 0, nlines-1,
      (int (*)(void*,void*))(numeric ? numcmp : (foldcase ? strcmp_f : strcmp1)), reverse);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}


void qsort1(void *v[], int left, int right, int (*comp)(void *, void *), int reverse) {
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right)/2);
  last = left;
  if (reverse) {
    for (i = left+1; i <= right; i++) {
      if((*comp)(v[i], v[left]) > 0)
        swap(v, ++last, i);
    }
  } else {
    for (i = left+1; i <= right; i++) {
      if((*comp)(v[i], v[left]) < 0)
        swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort1(v, left, last-1, comp, reverse);
  qsort1(v, last+1, right, comp, reverse);
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void writelines(char *lineptr[], int nlines) {
  int i;

  for (i=0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;

  while ((len = getline1(line, MAXLEN)) > 0) {
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