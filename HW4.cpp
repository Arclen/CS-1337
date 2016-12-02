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
   camp.width=10;
   build.width=5;
   camp.height=8;
   build.height=7;
   Campus UTD(camp, build);
/*
   Position pos;
   pos.pos_x=5;
   pos.pos_y=5;
   Student John("John", "Go f urself", pos, 20);
*/

    Student John("John", "Cena", 69);
    Student Jane("Jane", "Eyre", 120);
    John.go_to_campus(UTD);
    Jane.go_to_campus(UTD);
    cout<<UTD;
    int moves = 0;
    while(moves<35)//UTD.numTrash() != 0)
    {
        John.move(UTD);
        Jane.move(UTD);
        //cout<<UTD.numTrash()<<"\n";
        //cout<<John.getNumTrash()<<" "<<Jane.getNumTrash()<<"\n";
        cout<<UTD;
        cout<<"---------------------\n";
        moves++;
    }
    /*if(John.getGrade() == Jane.getGrade())
        cout<<"A tie! Both students have a grade of: "<< Jane.getGrade();
    else if(John.getGrade() < Jane.getGrade())
        cout<<"Jane wins with a grade of: "<<Jane.getGrade();
    else cout<<"John wins with a grade of: "<<John.getGrade();*/

}
