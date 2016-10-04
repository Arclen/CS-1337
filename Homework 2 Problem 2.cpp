// Jacob Liou CS 1337
#include <iostream>
#include <string>
void switchEnds(int *, int);
void switcheroo(int *, int *);
int main()
{
  int array[] = {1,2,3,4,5,6,7,8};
  for(int i=0; i<8; i++)
  {
      std::cout<<array[i]<<" ";
  }
  int size = 8;
  switchEnds(array,8);
  for(int i=0; i<8; i++)
  {
      std::cout<<array[i]<<" ";
  }
}
void switchEnds(int *array, int size)
{
    int *x = array;
    int *y = array+size-1;
    int temp = *x;
    *x = *y;
    *y = temp;
    std::cout<<"\nSwitched!\n";
}
