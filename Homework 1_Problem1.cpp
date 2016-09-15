//Jacob Liou CS 1337
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int [], int);
void selectionSort(int[], int);
void resetA(int [], int);
int main()
{
    int A[] = {25,9,3,7,11,0,2,20,28,5,16};
    bubbleSort(A, 11);
    resetA(A, 11);
    selectionSort(A,11);
        for(int i=0; i<11; i++)
        {
            std::cout<<A[i]<<" ";
        }

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
}

void selectionSort(int array[], int size)
{
    int startScan, minIndex, minValue;
    for(startScan = 0; startScan < (size-1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
            minValue = array[index];
            minIndex = index;
            }
            for(int i=0; i<size; i++)
            {
                std::cout<<array[i]<<" ";
            }
            std::cout<<"\n";
        }

        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}
void resetA(int array[], int size)
{
    int temp[] = {25,9,3,7,11,0,2,20,28,5,16};
    for(int i=0; i<size; i++)
    {
        array[i] = temp[i];
    }
}
