// Jacob Liou CS 1337
#include <iostream>
#include <string>
void switchEnds(int *, int);
void switcheroo(int *, int *);
int main()
{
  int array[] = {1,2,3,4,5};
  int size = 5;
  switchEnds(array,5);
  std::cout<<array[0]<<" "<<array[4];
}
void switchEnds(int *array, int size)
{
    switcheroo(array, array+size-1);
}
void switcheroo(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
