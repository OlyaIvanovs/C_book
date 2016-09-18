#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAXOP 100
#define NUMBER '0'
#define MATH '1'
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void swap();
void dublicate();
void ungetch(int);
void showTop();
void mathfunc();
 
int sp = 0;  /* next free stack position */
double val[MAXVAL];  /* value stack */
char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */



int main() {
  int type;
  double op2, op1, op3;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case MATH:
        mathfunc(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop()*pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      case '%':
        op2 = pop();
        op1 = pop();
        if (op2 != 0.0) {
          push(op1 - (int)(op1 / op2) * op2);
        }
        break;
      case '&':
        showTop();
        break;
      case '}':
        dublicate();
        break;
      case '$':
        swap();
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("error: stack full, cant push %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (!isalnum(c) && c != '.' && c != '-') {
    return c;
  }

  i = 0;

  if (isalpha(c)) {
    while (isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF) {
      ungetch(c);
    }
    return MATH;
  }

  if (c == '-') {
    if (!isdigit(c = getch())) {
      return '-';
    } else {
      s[++i] = c;
    }
  }
  
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';
  if (c != EOF) {
    ungetch(c);
  }
  return NUMBER;
}

/* get a (possibly pushed-back) character */
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}


/* push character back on input */
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}


// to print the the top elements of the stack
void showTop(void) {
  if (sp > 0) {
    printf("%8g\n", val[sp-1]);
  } else {
    printf("error: stack empty\n");
  }
}

// to dublicate the the top elements of the stack
void dublicate() {
  double el = pop();

  push(el);
  push(el);
}

void swap() {
  double op1, op2;

  op1 = pop();
  op2 = pop();
  push(op2);
  push(op1);
}

void mathfunc(char s[]) {
  int type;

  printf("mathfunc");
  printf("%s\n", s);

  if(strcmp(s, "sin")) {
    printf("lalalal");
  }

/*  switch(s) {
    case "sin":
      printf("sin");
      break;*/
}