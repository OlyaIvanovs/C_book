#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define MAXWORD 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


struct tnode {
  char *name;
  struct tnode *parent;
};

char *keywords[] = {
  "a", "div", "h1", "p" 
};

#define NKEYS (sizeof keywords / sizeof(keywords[0]))

struct tnode *stack[MAXLEN];

int getch(void);
void ungeth(int c);
int getword(char *word, int lim);
struct tnode *addnode(struct tnode *p, char *w);
int binsearch(char *word, char *keywords[], int n);
char *my_strdup(char *s);
struct tnode *talloc(void);

static int stack_size;

int main() {
  struct tnode *root;
  char word[MAXWORD];
  int k;
  int i = 0;

  root = NULL;
  while (getword(word, MAXWORD) != EOF) {;
    if ((binsearch(word, keywords, NKEYS)) >= 0) {
      root = addnode(root, word);
    }
    stack[i] = root;
    stack_size = i;
    i++;
  }
  for (k=0; k<i; k++) {
    printf("%s\n", stack[k]->name);
    if (stack[k]->parent != NULL) {
      printf("parent %s\n", stack[k]->parent->name);
    }
  }
  return 0;
}

struct tnode *addnode(struct tnode *p, char *w) {
  int cond;

  p = talloc(); /* make a new node */
  p->name = my_strdup(w);
  p->parent = stack[stack_size];
  return p;
}

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch())) 
    ;

  if ( (c == '<') && (isalpha(c = getch()))) {
    *w++ = c;
    while ((c = getch()) != '>'){
      *w++ = c;
    }
    *w = '\0';
    return word[0];
  }

  if (!isalpha(c)) {
    *w = '\n';
    return c;
  }
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

int binsearch(char *word, char *keywords[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low+high) / 2;
    if ((cond = strcmp(word, keywords[mid])) < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

char *my_strdup(char *s) {
  char *p;

  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

struct tnode *talloc(void) {
  return  (struct tnode *) malloc(sizeof(struct tnode));
}