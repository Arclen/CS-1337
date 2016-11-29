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
    /*Trash t;
    cout<<t;
    t.removeTrash();
    cout<<t;*/
   Dimension camp, build;
   camp.width=16;
   build.width=5;
   camp.height=14;
   build.height=7;
   Campus UTD(camp, build);
/*
   Position pos;
   pos.pos_x=5;
   pos.pos_y=5;
   Student John("John", "Go f urself", pos, 20);
*/

    Student John, Jane;
    John.go_to_campus(UTD);
    Jane.go_to_campus(UTD);
    cout<<UTD;
    int moves = 0;
    while(UTD.numTrash() != 0)
    {
        John.move(UTD);
        Jane.move(UTD);
        cout<<UTD.numTrash()<<"\n";
        cout<<UTD;
        moves++;
    }

}
