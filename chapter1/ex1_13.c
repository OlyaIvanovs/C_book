#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
  int c, i, b, k, v, r, m;
  int n; // кол-во слов
  int w_len; //  кол-во букв в слове
  int words_max;
  int state;
  int words[n]; // массив кол-ва букв в словах

  w_len = 0;
  n = 0; 
  
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        state = OUT;
        words[n] = w_len;       
        w_len = 0; // обнуляем кол-во букв для сл слова 
        ++n; //следующее слово
      }
    } else {
      state = IN;
      ++w_len; 
    }
  }


  // отрисовка горизонтальная
  printf("Horisontal\n");
  for (i = 0; i < n; i++) {
    b = words[i];
    for (k = 0; k < b; k++) {
      printf("*");
    }
    printf("\n");
  }

  //max
  words_max = words[0];
  for (i = 1; i < n; i++) {
      if (words[i] > words_max) {
        words_max = words[i];
      }
  }

  // отрисовка вертикальная
  printf("\n\n\n");
  printf("Vertical\n");
  for (m =0; m < words_max; m++) {
    for (v = 0; v < n; v++) {
      if (words[v] > 0) {
        words[v] = words[v] - 1;
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

}