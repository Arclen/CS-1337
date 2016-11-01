//Jacob Liou CS 1337

using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Campus.h"

int main()
{
    Campus camp1(25, 15);
    cout<<camp1.getCampusDimension()<<" "<<camp1.getBuildingDimension()<<"\n";
    cout<<camp1;

    Campus camp2(5, 100);
    cout<<camp2;
}
