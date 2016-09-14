#include <stdio.h>

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high)/2;
    if (x <= v[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  
  if (x == v[low]) {
    return low;
  } else {
    return high;
  }

  return -1;
}

int main() {
  int x, n, c;
  int v[] = {2, 3, 5, 6, 8, 9, 12, 16, 17, 19, 23, 39};

  x = 39;
  n = 12;
  c = binsearch(x, v, n);
  printf("%d\n", c);
}