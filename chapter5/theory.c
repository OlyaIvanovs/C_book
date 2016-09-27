#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max;)

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while (c = *++argv[0]) {
      switch(c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("find: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
    }
  }

  if (argc != 1) {
    printf("Usage: find pattern\n");
  } else {
    while (getline(line, MAXLINE) > 0) {
      if(strstr(line, argv[1]) != NULL) {
        printf("%s", line);
        found++;
      }
    }
  }
}