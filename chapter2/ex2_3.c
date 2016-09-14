#include <stdio.h>

int htoi(char s[]) {

}


int main() {
  char s[] = "0XFF12";
  int n, i;
  char c;

  n = 0;
  for (i=0; s[i] != '\0'; ++i) {
    if (s[i] == '0') {
      i++;
      if (s[i] == 'x' || s[i] == 'X') {
        continue;
      }
    } else if (s[i] >= '0' && s[i] <= '9') {
      n = 16 * n + (s[i] - '0');
    } else if (s[i] >= 'a' && s[i] <= 'f')  {
      n = 16 * n + 10 + (s[i] - 'a');
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      n = 16 * n + 10 + (s[i] - 'A');
    }
    else {
      printf("error");
      break;
    }
  }
  printf("%d", n);
}