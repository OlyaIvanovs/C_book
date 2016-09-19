#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"


#define MAXOP 100
#define NUMBER '0'
#define MATH '1'


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