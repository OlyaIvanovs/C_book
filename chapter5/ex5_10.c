#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;  /* next free stack position */
double val[MAXVAL];  /* value stack */

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

// expr , which evaluates a reverse Polish expression from the command line
int main(int argc, char *argv[]) {
  int type, k;
  double op2;
  char c;

  while (--argc > 0) {
    *++argv;
    if (isdigit(**argv)) {
      type = NUMBER;
    } else {
      type = **argv;
    }
    switch(type) {
      case NUMBER:
        push(atof(*argv));
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
      default:
        printf("error: unknown command %c\n", type);
        break;
      }
  }
  
  if (sp == 1) {
    printf("%.2f\n", val[0]);
  }
}

