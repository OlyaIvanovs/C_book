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

struct tnode_word {
  char *root;
  int count;
  struct tnode_word *left;
  struct tnode_word *right;
};

struct tnode *addtree_root(struct tnode *, char *, int n);
struct tnode *talloc(void);
void addsubtree(struct tnode *p);
void treeprint(struct tnode *);

struct tnode_word *addtree(struct tnode_word *, char *);
struct tnode_word *walloc(void);
void subtreeprint(struct tnode_word *);

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
      root = addtree_root(root, word, first);
    }
  }
  printf("\n\nDUBLICATE LISTS:\n");
  addsubtree(root);
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
    p->left = addtree_root(p->left, w, n);
  } else {
    p->right = addtree_root(p->right, w, n);
  }
  return p;
}


struct tnode_word *addtree(struct tnode_word *p, char *w) {
  int cond;

  if (p == NULL) {
    p = walloc(); /* make a new node */
    p->root = my_strdup2(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->root)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }
  return p;
}


void addsubtree(struct tnode *p) {
  int i;
  struct tnode_word *root;

  root = NULL;
  if (p != NULL && p->count > 1) {
    addsubtree(p->left);
    for (i = 0; i < p->count; i++)  {
      root = addtree(root, p->words[i]);
    }
    printf("\nROOT: %s %d\n", p->root, p->count);
    subtreeprint(root);
    addsubtree(p->right);
  }
}

void subtreeprint(struct tnode_word *p) {
  if (p != NULL) {
    subtreeprint(p->left);
    printf("\t\t%s %d\n", p->root, p->count);
    subtreeprint(p->right);
  }
}


struct tnode *talloc(void) {
  return  (struct tnode *) malloc(sizeof(struct tnode));
}


struct tnode_word *walloc(void) {
  return  (struct tnode_word *) malloc(sizeof(struct tnode_word));
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

  //Skip comments
  if (c == '/' && (c = getch()) == '*') {
    while ((c = getch()) != '*')
      ;
    if ((c = getch())  == '/') {
      *w = '\n';
      return c;
    }
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