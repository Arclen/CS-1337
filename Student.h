//Jacob Liou CS 1337

using namespace std;
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "Campus.h"
#include "Trash.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Student: public Person{

        friend class Campus;
        friend class Trash;

    private:
        string fname;
        string lname;
        Position pos;
        int iq;
        //Trash pockets[10];


    public:
        Student()
        {
            fname = "Bob";
            lname = "Doherty";
            iq = rand() % 20 + 50;
            pos.pos_x = 10;
            pos.pos_y = 10;
        }

        void go_to_campus(Campus c)
        {
            c.placeStudent();
            cout<<"go_to_campus debug";
        }
        Student(string f, string l, Position p, int q)
        {
            fname = f;
            lname = l;
            pos.pos_x = p.pos_x;
            pos.pos_y = p.pos_y;
            iq = q;
        }

        void setIQ(int i)
        {
            iq = i;
        }

        int getIQ()
        {
            return iq;
        }

        /*void studentMove()
        {
            int i = rand() % 4 + 1;
            switch(i)
            {
            case 1:
                if(xpos>0)
                    xpos--;
                break;
            case 2:
                if(ypos>0)
                    ypos--;
                break;
            case 3:
                if(xpos<25)
                    xpos++;
                break;
            case 4:
                if(ypos<25)
                    ypos++;
                break;
            }
        }
*/


        friend ostream& operator<<(ostream& os, const Student &stu)
        {
             os << stu.fname << " " << stu.lname
                << " has iq " << stu.iq
                << " and is at (" << stu.pos.pos_x<< ", "<< stu.pos.pos_y<< ")";
        }


};
#endif // STUDENT_H_INCLUDED
