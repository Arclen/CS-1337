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
public:
    void studentPos();
    void studentOutput();
    void studentMove();

    Student(){
        name = "Bob";
        iq = rand() % 20 + 50;
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
