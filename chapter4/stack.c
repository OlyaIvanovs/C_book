#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define MAXVAL 100

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
  ++sp;
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
  double op2;

  if(strcmp(s, "sin") == 0) {
    if (sp > 0) {
      push(sin(pop()));
    } else {
      printf("error: stack empty\n");
    }
  } else if(strcmp(s, "cos") == 0) {
    if (sp > 0) {
      push(cos(pop()));
    } else{
      printf("error: stack empty\n");
    }
  } else if(strcmp(s, "exp") == 0) {
    if (sp > 0) {
      push(exp(pop()));
    } else{
      printf("error: stack empty\n");
    }
  } else if(strcmp(s, "pow") == 0) {
    if (sp > 1) {
      push(pow(pop(), pop()));
    } else{
      printf("error: stack empty\n");
    }
  }
}