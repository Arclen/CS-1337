//Jacob Liou CS 1337

using namespace std;
#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include "Campus.h"
#include "Trash.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Teacher: public Person{

    friend class Student;
    friend class Campus;

    private:
        Position pos;

    public:
        void gradeProject(Student& s)
        {
            int mood = rand() % 2;
            switch(mood)
            {
            case 0:
                cout<<"Good job, "<<s.fname<<"! You get a grade of "<<s.grade<<"\n";
            break;

            case 1:
                    cout<<"Good job, "<<s.fname<<"! You get a grade of "<<s.grade
                        <<"\nHowever, I am in a bad mood today, so I'm deducting 5 points!\n";
                    s.grade -= 5;
            break;

            case 2:
                    cout<<"Good job, "<<s.fname<<"! You get a grade of "<<s.grade
                    <<"\nHowever, I am in a good mood today, so I'm adding 5 points!\n";
                    s.grade += 5;
            break;
            }
        }

};

#endif // TEACHER_H_INCLUDED
