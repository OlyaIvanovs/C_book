#include <stdio.h>

int lower(int c)
{
(c >= 'A' && c <= 'Z') ? (c = (c + 'a' - 'A')) : c;
return c;
}


int main() {
  int c;

  c = getchar();
  putchar(lower(c));
}