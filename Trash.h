//Jacob Liou CS 1337

using namespace std;
#ifndef TRASH_H_INCLUDED
#define TRASH_H_INCLUDED
#include "Campus.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Trash
{
    friend class Student;
    friend class Campus;

    private:
        string name;
        int value;

    public:
        Trash()
        {
            fstream file;
            string input;
            char temp[10];

            file.open("trash.txt");
            getline(file,input);
            strcpy(temp,input.c_str());
            int length = atoi(temp);

            string tnames[length];
            int tvals[length];
            int looper = 0;


            while(!file.eof())
            {
                getline(file,input,' ');
                tnames[looper] = input;

                getline(file,input);
                strcpy(temp,input.c_str());
                tvals[looper] = atoi(temp);

                looper++;
            }
            file.close();

            int index = rand() % 10;
            name = tnames[index];
            value = tvals[index];

            //cout<<name<<value;
            }

            void removeTrash()
            {
                name = " ";
                value = 0;
            }

            friend ostream& operator<<(ostream& os, const Trash &tr)
            {
                cout<<tr.name<<" "<<tr.value<<"\n";
            }
};

#endif // TRASH_H_INCLUDED
