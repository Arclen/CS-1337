using namespace std;
#include <iostream>
#include "Student.h"
#include "Campus.h"
#include <string>
#include <stdlib.h>


int main()
{
    Campus camp(5, 5);
    cout<<camp;
    Student students[10];
    for(int i=0; i<10; i++)
        cout<<students[i]<<"\n";

}
