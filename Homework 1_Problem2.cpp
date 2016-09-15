//Jacob Liou CS 1337
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void bubbleSort(int [], int);
void createRandomArray(int[], int);
int main()
{
  int size;
  std::cout<<"Please enter the size of the array "<<"\n";
  std::cin >> size;
  int rand[size];
  createRandomArray(rand, size);
  bubbleSort(rand, size);
}
void bubbleSort(int array[], int size)
{
    bool swap;
    int temp;
    do
    {
        swap = false;
        for(int count = 0; count < (size-1); count++)
        {
            if (array[count] > array[count + 1])
            {
            temp = array[count];
            array[count] = array[count + 1];
            array[count + 1] = temp;
            swap = true;
            }
            for(int i=0; i<size; i++)
            {
                std::cout<<array[i]<<" ";
            }
            std::cout<<"\n";
        }
    } while (swap);
    std::cout<<"Sorted!"<<"\n";
}
void createRandomArray(int array[], int size)
{
  for(int i=0; i<size; i++)
  {
    std::srand(time(NULL)+i);
    array[i] = rand() % 200 - 100;
  }
}
