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

    private:
        string fname;
        string lname;
        int xpos, ypos;
        int iq;
        Trash pockets[10];

        void go_to_campus(Campus &camp)
        {
            xpos = rand() % 24;
            ypos = rand() % 24;
        }
    public:
        Student()
        {
            fname = "Bob";
            lname = "Doherty";
            iq = rand() % 20 + 50;
            //Campus camp(5,5);
            //go_to_campus(camp);
        }

        Student(string f, string l, int x, int y, int q)
        {
            fname = f;
            lname = l;
            xpos = x;
            ypos = y;
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

        void studentMove()
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



        friend ostream& operator<<(ostream& os, const Student &stu)
        {
             os << stu.fname << " " << stu.lname
                << " has iq " << stu.iq
                << " and is at (" << stu.xpos << ", "<< stu.ypos << ")";
        }

        friend class Campus;

};
#endif // STUDENT_H_INCLUDED
