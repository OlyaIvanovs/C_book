#include <stdio.h>

void strcat1(char *s, char *t) {
  while (*s != '\0') {
    s++;
  }
  for ( ; *s == *t; s++, t++) {
    if (*s == '\0') {
      printf("%s", s);
    }
  }
    
  return;

  // while ((*s = *t) != '\0') {
  //   printf("mmmm");
  //   s++;
  //   t++;
  // }
  // printf("%s", s);
}


int main() {
  char *s;
  char *t;

  s = "mama";
  t = "myla ramu";

  strcat1(s, t);

}