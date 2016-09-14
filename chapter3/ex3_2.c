#include <stdio.h>

void escape(char s1[]) {
  int i, j;
  char s2[100000];

  for (i=j=0; s1[i] != '\0'; ++i) {
    printf("%c", s1[i]);
    if (s1[i] == '\t') {
      printf("dsjkgjsdkg");
    }
    switch(s1[i]) {
      case '\t':
        printf("hsjfh");
        s2[j++] = '\\';
        s2[j] = 't';
        break;
      default:
        s2[j] = s1[i]; 
        break;
    }
    j++;
  }
  // s2[j] = '\0';
  // printf("%s", s2);

}

int main() {
  int c;
  char str1[] = "dfd    fdfd     kuj ";

  escape(str1);

}