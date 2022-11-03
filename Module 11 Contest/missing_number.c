#include <stdio.h>

int main() {

  int a,b,c,missed,sum,T;

  scanf("%d",&T);
  while(T--)
  {

    scanf("%d%d %d %d",&sum,&a,&b,&c);
    missed=sum-(a+b+c);
    printf("%d\n",missed);
  }
  return 0;
}