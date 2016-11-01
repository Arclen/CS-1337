//Jacob Liou CS 1337

using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Student.h"

int main()
{
    Student charlie("Charlie", 4, 20, 420);
    cout<<charlie.getIQ()<<"\n";
    charlie.setIQ(69);
    cout<<charlie<<"\n";

    for(int i=0; i<10; i++)
    {
        charlie.studentMove();
        cout<<charlie<<"\n";
    }

    Student students[10];
    for(int i=0; i<10; i++)
        cout<<students[i]<<"\n";
}
