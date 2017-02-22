//#include<stdio.h>
//void main()
//{
//register int a=5;
//}
int main()
{
  register int i = 10;
  int *a = &i;
  printf("%d", *a);
  getchar();
  return 0;
}
