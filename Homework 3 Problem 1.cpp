using namespace std;
#include <iostream>
#include "Student.h"
#include "Campus.h"
#include <string>
#include <stdlib.h>


int main()
{
    Campus camp(25, 15);
    cout<<camp;
    Student students[10];
    for(int i=0; i<10; i++)
        cout<<students[i]<<"\n";

}
