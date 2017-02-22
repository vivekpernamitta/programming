
#include<stdio.h>

struct Array_by_val
{
  int my_array[10];
};

void func (Array_by_val x) {}

int main() {
   Array_by_val x;
   func(x);
}
