#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define MAXWORD 100
#define BUFSIZE 100

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

char buf[BUFSIZE];
int bufp = 0;

struct stylenode {
  int height;
  int width;
  int bg;
};

struct tnode {
  char *name;
  char *classname;
  struct tnode *parent;
  struct stylenode *css;
};

char *keywords[] = {
  "a", "div", "h1", "p", "span"
};

#define NKEYS (sizeof keywords / sizeof(keywords[0]))

struct tnode *stack[MAXLEN];
struct tnode *tags_stack[MAXLEN];

int getch(void);
void ungeth(int c);
int getword(char *word);
struct tnode *addnode(struct tnode *p, char *w);
int binsearch(char *word, char *keywords[], int n);
char *my_strdup(char *s);

struct tnode *talloc(void);
struct stylenode *salloc(void);

static int stack_size;

int main() {
  struct tnode *root;
  char word[MAXWORD];
  char styleline[MAXLEN];
  char param[MAXLEN];
  char value[MAXLEN];

  int k, l, c, n;
  int i = 0;
  int m = 0;

  root = NULL;
  while (getword(word) != EOF) {
    // для закрывающего тега
    if (word[0] == '/') {
      l = 1;
      while(word[l] != '\0') {
        word[l-1] = word[l];
        l++;
      }
      word[l-1] = '\0';
      // удаления тега из списка
      if ((binsearch(word, keywords, NKEYS)) >= 0) {
        if (strcmp(stack[stack_size]->name, word) == 0) {
          stack[stack_size] = NULL;
          stack_size--;
          i--;
        } else {
          printf("Error: missing %s tag\n", stack[stack_size]->name);
          return 0;
        }
      }
      // открывающийся тег
    } else if ((binsearch(word, keywords, NKEYS)) >= 0) {
      root = addnode(root, word);
      stack[i] = root;
      tags_stack[m] = root;
      stack_size = i;
      i++;
      m++;
      // Yазвание класса
    } else if (strcmp("class", word) == 0) {
      while (getword(word) != '>') {
        if (isalpha(word[0])) {
          stack[stack_size]->classname = my_strdup(word);
          break;
        }
      }
      //стили
    } else if (strcmp("style", word) == 0) {
      while (getword(word) != '"') ;
      while (getword(word) != '"') {
        if (strcmp("height", word) == 0) {
          while (getword(word) != ';') {
            if (isalnum(word[0])) {
              stack[stack_size]->css->height = atoi(word);
            }
          }
        } else if (strcmp("width", word) == 0){
          while (getword(word) != ';') {
            if (isalnum(word[0])) {
              stack[stack_size]->css->width = atoi(word);
            }
          }
        }
      }
    }
  }


  for (k=0; k<i; k++) {
    printf("Error: missing %s tag\n", stack[k]->name);
  }


  // print all tags
  for (k=0; k<m; k++) {
    printf(ANSI_COLOR_BLUE "tag:" ANSI_COLOR_RESET "%s\n", tags_stack[k]->name);
    if (tags_stack[k]->parent != NULL) {
      printf(ANSI_COLOR_RED "parent:" ANSI_COLOR_RESET "%s.%s\n", 
        tags_stack[k]->parent->name, tags_stack[k]->parent->classname);
    }
    printf(ANSI_COLOR_GREEN "class:" ANSI_COLOR_RESET "%s\n", tags_stack[k]->classname);
    printf("\n");
  }

  // find siblings/find childrens
  printf("Chilfren for first el\n");
  for (k=1; k<m; k++) {
    if ((tags_stack[k]->parent) == tags_stack[0]) {
      printf("%s\n", tags_stack[k]->name);
    }
  }
  return 0;
}

struct tnode *addnode(struct tnode *p, char *w) {
  int cond;

  p = talloc(); /* make a new node */
  p->name = my_strdup(w);
  p->parent = stack[stack_size];
  p->classname = NULL;
  p->css = salloc();
  return p;
}

struct stylenode *addstyle(struct stylenode *p) {
  p->height = 0;
  p->width = 0;
  p->bg = 0;
  return p;
}

int getword(char *word) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()))  
    ;

  if ( (c == '<') && (isalpha(c = getch()) || (c == '/'))) {
    *w++ = c;
    while (isalnum(c = getch())) {
      *w++ = c;
    }
    *w = '\0';
    return word[0];
  } 

  if (isalnum(c)) {
    *w++ = c;
    while (isalnum(c = getch())) {
      *w++ = c;
    }
    ungetch(c);
    *w = '\0';
    return word[0];
  } else {
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

struct stylenode *salloc(void) {
  return  (struct stylenode *) malloc(sizeof(struct stylenode));
}