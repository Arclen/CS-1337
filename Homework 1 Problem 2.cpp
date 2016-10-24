//Jacob Liou CS 1337
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
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
    int comp = 0;
    int moves = 0;
    std::cout<<"Initial array: ";
    for(int i=0; i<size; i++)
            {
                std::cout<<array[i]<<" ";
            }
    std::cout<<"\n";
    clock_t t = clock();
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
                moves++;
            }
            comp++;
        }
    } while (swap);
//This gives the time elapsed
    t = clock() - t;
    std::cout<<"Sorted! \nNumber of comparisons: "<<comp<<" \nNumber of swaps: "<<moves<<" \nTime elapsed: "<<t<<" milliseconds.\n";
    for(int i=0; i<size; i++)
            {
                std::cout<<array[i]<<" ";
            }
}
void createRandomArray(int array[], int size)
{
//this loop assigns a random value to each spot in the array
  for(int i=0; i<size; i++)
  {
//the purpose of using both null time and the alternating signs is to
//ensure as much randomness as possible, as srand is not truly random
    srand(time(NULL)*2*(-1)^(i));
//this ensures that all integers from -100 to 99 are possibilities
    array[i] = rand() % 200 - 100;
  }
}
