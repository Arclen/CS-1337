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
        void studentMove();

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

        int getIQ(){
            return iq;
        }

        friend ostream& operator<<(ostream& os, const Student& stu)
        {
             os << stu.name << " has iq " << stu.getIQ()
                << " and is at (" << stu.xpos << ", "<< stu.ypos << ")";
        }

};
#endif // STUDENT_H_INCLUDED
