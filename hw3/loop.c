#include <stdio.h>
#include <string.h>
#include <time.h>

long long d[9999999];

void main() {
  for (long long i = 0; i < 9999999; i++) {
    d[i] = i;
  }

  printf("OP = +\n");
  clock_t start = clock();
  long long ans = 1;
  for (long long i = 0; i < 9999999; i++) {
    ans = ans + d[i];
  }
  clock_t end = clock();
  printf("%ld time spent\n", (long)end - start);

  start = clock();
  ans = 1;
  for (long long i = 0; i < 9999999; i += 2) {
    ans = ans + (d[i] + d[i + 1]);
  }
  end = clock();
  printf("Loop unrolled 2*1a: %ld time spent\n", (long)end - start);

  start = clock();
  long long ans1 = 1;
  long long ans2 = 1;
  for (long long i = 0; i < 9999999; i += 2) {
    ans1 = ans1 + d[i];
    ans2 = ans2 + d[i + 1];
  }
  end = clock();
  printf("Loop unrolled 2*2: %ld time spent\n", (long)end - start);

  printf("OP = *\n");
  start = clock();
  ans = 1;
  for (long long i = 0; i < 9999999; i++) {
    ans = ans * d[i];
  }
  end = clock();
  printf("%ld time spent\n", (long)end - start);

  start = clock();
  ans = 1;
  for (long long i = 0; i < 9999999; i += 2) {
    ans = ans * (d[i] * d[i + 1]);
  }
  end = clock();
  printf("Loop unrolled 2*1a: %ld time spent\n", (long)end - start);

  start = clock();
  ans1 = 1;
  ans2 = 1;
  for (long long i = 0; i < 9999999; i += 2) {
    ans1 = ans1 * d[i];
    ans2 = ans2 * d[i + 1];
  }
  end = clock();
  printf("Loop unrolled 2*2: %ld time spent\n", (long)end - start);
}