#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
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
    void studentOutput();
    void studentMove();

    Student(){
        name = "Bob";
        iq = rand() % 20 + 50;
        studentPos();
    }

    Student(string n, int x, int y, int q){}

    void setIQ(int i)
    {
        iq = i;
    }
    int getIQ(){
        return iq;
    }

};
#endif // STUDENT_H_INCLUDED
