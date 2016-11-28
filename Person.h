//Jacob Liou CS 1337

using namespace std;
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

class Person{

    private:
        string fname;
        string lname;
        int iq;

    public:
        Person()
        {
            fname = "";
            lname = "";
            iq = 0;
        }

        Person(string f, string l, int i)
        {
            fname = f;
            lname = l;
            iq = i;
        }
        void setfname(string f)
        {
            fname = f;
        }

        string getfname()
        {
            return fname;
        }

        void setlname(string l)
        {
            lname = l;
        }

        string getlname()
        {
            return lname;
        }

        void setIQ(int i)
        {
            iq = i;
        }

        int getIQ()
        {
            return iq;
        }

        friend ostream& operator<<(ostream& os, const Person &per)
        {
             os << per.fname<< " " << per.lname
                << " has iq " << per.iq;
        }
};
#endif // PERSON_H_INCLUDED
