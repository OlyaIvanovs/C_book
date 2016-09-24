#include <stdio.h>
#include <string.h>

#define MAXLINE 100

// compare at most n characters of string cs to string ct ; return <0 if
// cs<ct , 0 if cs==ct , or >0 if cs>ct .
int my_strncmp(char *s, char *t, int n) {
  int k;
  for ( k=0; *s == *t; s++, t++, ++k) {
    if (k >= n || *s == '\0') {
      return 0;
    }
  }
  return *s - *t;
}

int main() {
  int n, res, my_res;
  char s[MAXLINE] = "mama myla ramu";
  char t[MAXLINE] = "m";
  n = 5;

  my_res = my_strncmp(s, t, n);
  printf("Result of standart strncmp %d\n", my_res);
  res = strncmp(s, t, n);
  printf("Result of standart strncmp %d\n", res);

}