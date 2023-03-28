#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {
  char s[] = "dog";
  char t[] = "house";
  char u[] = "rainbow";
  printf("%p: %s\n", s, s);
  printf("%p: %s\n", t, t);
  printf("%p: %s\n", u, u);
  printf("\n");
  strcat(s, u);
  printf("%s\n", s);  // dograinbow
  printf("%s\n", t);  // house
  printf("%s\n", u);  //
}