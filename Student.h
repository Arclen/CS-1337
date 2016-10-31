#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Student{

    private:
        string name;
        int xpos, ypos;
        int iq;

        void studentPos()
        {
            xpos = rand() % 24;
            ypos = rand() % 24;
        }
    public:
        Student()
        {
            name = "Bob";
            iq = rand() % 20 + 50;
            studentPos();
        }

        Student(string n, int x, int y, int q)
        {
            name = n;
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
            //ask Prof Feng if in future, students can be in trash space
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
             os << stu.name << " has iq " << stu.iq << " and is at (" << stu.xpos << ", "<< stu.ypos << ")";
        }

};
#endif // STUDENT_H_INCLUDED
