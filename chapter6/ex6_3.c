#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
static int number_line;

struct tnode {
  char *word;
  int count;
  int lines[1000];
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int n);
struct tnode *talloc(void);
void treeprint(struct tnode *);
int getword(char *, int);
char *my_strdup(char *s);
int binsearch(int x, int v[1000]);


int main() {
  struct tnode *root;
  char word[MAXWORD];
  int line = 0;
  int c;
  root = NULL;

  while ((c = getword(word, MAXWORD)) != EOF) {
    if (isalpha(c)) {
      root = addtree(root, word, number_line);
    }
  }
  treeprint(root);
  return 0;
}
  
struct tnode *addtree(struct tnode *p, char *w, int n) {
  int cond;

  if (p == NULL) {
    p = talloc(); /* make a new node */
    p->word = my_strdup(w);
    p->count = 1;
    p->lines[0] = n;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->lines[p->count] = n;
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w, n);
  } else {
    p->right = addtree(p->right, w, n);
  }
  return p;
}

struct tnode *talloc(void) {
  return  (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s) {
  char *p;

  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
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

void treeprint(struct tnode *p) {
  int i;
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\t\t", p->count, p->word);
    printf("Number lines: ");
    for (i=0; i<p->count; i++) {
      printf("%d, ", p->lines[i]);
    }
    printf("\n");
    treeprint(p->right);
  }
}

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  if ((c = getch()) == '\n') {
    number_line ++;
    return c;
  } else {
    ungetch(c);
  }

  while(isspace(c = getch())) {
    if (c == '\n') {
      ungetch(c);
      return c;
    }
  };

  if (c != EOF) {
    *w++ = c;
  }
  if (!isalpha(c)) {
    *w = '\n';
    return c;
  }
  for (; --lim > 0; w++) {
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}
