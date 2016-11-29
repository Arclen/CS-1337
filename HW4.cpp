//Jacob Liou CS 1337

using namespace std;
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Campus.h"
#include "Trash.h"
#include <string>
#include <stdlib.h>

int main()
{
    //Trash t;
   Dimension camp, build;
   camp.width=12;
   build.width=7;
   camp.height=9;
   build.height=4;
   Campus test(camp, build);
/*
   Position pos;
   pos.pos_x=5;
   pos.pos_y=5;
   Student John("John", "Go f urself", pos, 20);
*/

    Student John;
   John.go_to_campus(test);
   //cout<<John;

   cout<<test;
}
