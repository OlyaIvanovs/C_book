#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

struct tnode {
  char *root;
  char *words[MAXWORD];
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree_root(struct tnode *, char *, int n);
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
void dublicateprint(struct tnode *);
int getword(char *, int);
char *my_strdup(char *s, int n);
char *my_strdup2(char *s);


/* word frequency count */
int main() {
  struct tnode *root;
  char word[MAXWORD];

  int first = 4;

  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      root = addtree(root, word, first);
    }
  }
  treeprint(root);
  return 0;
}

struct tnode *addtree_root(struct tnode *p, char *w, int n) {
  int cond;
  int k;

  if (p == NULL) {
    p = talloc(); /* make a new node */
    p->root = my_strdup(w, n);
    p->words[0] = my_strdup2(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strncmp(w, p->root, n)) == 0) {
    k = p->count;
    p->words[k] = my_strdup2(w);
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w, n);
  } else {
    p->right = addtree(p->right, w, n);
  }
  return p;
}


void treeprint(struct tnode *p) {
  int i;

  if (p != NULL) {
    treeprint(p->left);
    if (p->count > 1) {
      printf("%4d %s\n", p->count, p->root);
      for (i=0; i < p->count; i++) {
        printf("%s\n", p->words[i]);
      }
    }
    treeprint(p->right);
  }
}

struct tnode *talloc(void) {
  return  (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s, int n) {
  char *p;

  p = (char *)malloc(strlen(s) + 1);
  if (p != NULL)
    strncpy(p, s, n);
  return p;
}

char *my_strdup2(char *s) {
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

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch())) 
    ;

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