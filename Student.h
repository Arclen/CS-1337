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
        friend class Teacher;

    private:
        string fname;
        string lname;
        Position pos;
        int iq;
        int grade;
        bool projectGraded;
        Trash pockets[10];


    public:
        Student()
        {
            fname = "Bob";
            lname = "Doherty";
            iq = rand() % 20 + 50;
            pos = {0,0};
            projectGraded = false;

            //making sure there are no pre-existing trash objects
            for(int i=0; i<10; i++)
            {
                pockets[i].removeTrash();
            }
        }

        Student(string f, string l, int q)
        {
            fname = f;
            lname = l;
            pos = {0,0};
            iq = q;
            projectGraded = false;

            //making sure there are no pre-existing trash objects
            for(int i=0; i<10; i++)
            {
                pockets[i].removeTrash();
            }
        }

        void showProj()
        {
            cout<<"\n"<<fname<<"'s Project: ";
            for(int i=0; i<getNumTrash(); i++)
                cout<<pockets[i].name<<" ";
            cout<<endl;
        }
        void go_to_campus(Campus& c)
        {
            //ensuring student is placed in an empty cell
            bool emptySpace = false;
            if(pos.pos_x == 0 && pos.pos_y == 0)
                while(!emptySpace)
                {
                    int x=rand() % c.cdim.width;
                    int y=rand() % c.cdim.height;
                    if(c.area[x][y] == ' ')
                    {
                        pos.pos_x = x;
                        pos.pos_y = y;
                        c.area[x][y] = 'S';
                        emptySpace = true;
                    }
                }
            else c.area[pos.pos_x][pos.pos_y] = 'S';
        }

        void setIQ(int i)
        {
            iq = i;
        }

        int getIQ()
        {
            return iq;
        }

        bool isProjGraded()
        {
            return projectGraded;
        }
        void move(Campus& c)
        {
            //all trash is gone
            if (c.numTrash() == 0)
            {
                //student is inside the building
                if(pos.pos_x < c.bdim.width && pos.pos_y < c.bdim.height)
                {
                    c.area[pos.pos_x][pos.pos_y] = 'B';
                    int diffX = pos.pos_x - c.facPos.width;
                    int diffY = pos.pos_y - c.facPos.height;


                    if(diffX > 0)
                        pos.pos_x--;
                    else if(diffX < 0)
                        pos.pos_x++;
                    else if(diffY > 0)
                        pos.pos_y--;
                    else if(diffY < 0)
                        pos.pos_y++;

                    c.area[pos.pos_x][pos.pos_y] = 'S';

                    if(diffX == 0 && diffY == 0)
                    {
                        c.area[pos.pos_x][pos.pos_y] = 'F';
                        projectGraded = true;
                    }
                }
                //student is outside the building
                else {
                    c.area[pos.pos_x][pos.pos_y] = ' ';
                    int diffX = pos.pos_x - c.bdim.width+1;
                    int diffY = pos.pos_y - c.bdim.height+1;

                    if(diffX > 0)
                        pos.pos_x--;
                    else if(diffX < 0)
                        pos.pos_x++;
                    else if(diffY > 0)
                        pos.pos_y--;
                    else if(diffY < 0)
                        pos.pos_y++;

                    if(c.area[pos.pos_x][pos.pos_y] == 'B')
                    {
                        pos.pos_x++;
                        pos.pos_y++;
                        c.area[pos.pos_x][pos.pos_y] = 'S';
                    }
                    if(c.area[pos.pos_x][pos.pos_y] == 'D')
                    {
                        c.area[pos.pos_x][pos.pos_y] = 'S';
                    }
                    else if(c.area[pos.pos_x][pos.pos_y] == ' ')
                            c.area[pos.pos_x][pos.pos_y] = 'S';

                    if(c.area[c.bdim.width-1][c.bdim.height-1] == 'B')
                    c.area[c.bdim.width-1][c.bdim.height-1] = 'D';
                }
                if(c.area[c.bdim.width-1][c.bdim.height-1] == ' ')
                    c.area[c.bdim.width-1][c.bdim.height-1] = 'D';
            }
            //trash is still on campus
            else
            {
                c.area[pos.pos_x][pos.pos_y] = ' ';
                int i = rand() % 8 + 1;

                loop:
                    i = rand() % 8+ 1;
                    if(c.numTrash()>0)
                    switch(i)
                    {
                        case 1:
                        if(pos.pos_x>0)
                        {
                            pos.pos_x--;
                        }
                        else
                        {
                            goto loop;
                        }
                        break;
                    case 2:
                        if(pos.pos_y>0)
                        {
                            pos.pos_y--;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 3:
                        if(pos.pos_x<c.cdim.width-1)
                        {
                            pos.pos_x++;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 4:
                        if(pos.pos_y<c.cdim.height-1)
                        {
                            pos.pos_y++;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 5:
                        if(pos.pos_x>0 && pos.pos_y<c.cdim.height-1)
                        {
                            pos.pos_x--;
                            pos.pos_y++;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 6:
                        if(pos.pos_x<c.cdim.width-1 && pos.pos_y>0)
                        {
                            pos.pos_x++;
                            pos.pos_y--;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 7:
                        if(pos.pos_x<c.cdim.width-1 && pos.pos_y<c.cdim.height-1)
                        {
                            pos.pos_x++;
                            pos.pos_y++;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    case 8:
                        if(pos.pos_x>0 && pos.pos_y>0)
                        {
                            pos.pos_x--;
                            pos.pos_y--;
                        }
                        else
                        {
                            i = rand() % 8+ 1;
                            goto loop;
                        }
                        break;
                    }
                //trash code!
                if(c.getCell(pos) == 'T')
                {
                    //checking if pockets are full
                    if(getNumTrash() < 10)
                    {
                        int index = getNumTrash();
                        pockets[index] = Trash();
                        if(pockets[index].name == "bomb")
                        {
                            iq -= 2;
                            cout<<"!!!!!!\n!BOOM!\n!!!!!!\n"
                                <<"Uh oh! Looks like "<<fname<<" picked up a bomb!\n\n";
                            pockets[index].removeTrash();
                        }
                        else speak();
                        c.trash--;
                        c.area[pos.pos_x][pos.pos_y] = 'S';
                        grade += pockets[index].value;
                    }
                    //making sure least valuable item gets dropped
                    else
                    {
                        int mindex = 0;
                        for(int i=0; i<11; i++)
                        {
                            if(pockets[i].value < pockets[mindex].value)
                            {
                                mindex = i;
                            }
                        }
                        Trash newTrash = Trash();
                        if(pockets[mindex].value < newTrash.value)
                        {
                            pockets[mindex].removeTrash();
                            pockets[mindex] = newTrash;
                        }

                    }

                }
                else if(c.area[pos.pos_x][pos.pos_y] == ' ')
                        c.area[pos.pos_x][pos.pos_y] = 'S';
                else
                {
                    i = rand() % 8+ 1;
                    goto loop;
                }
            }

            }

        int getNumTrash()
        {
            int num =0;
            for(int i=0; i<10; i++)
                if(pockets[i].name != " ")
                    num++;
            return num;
        }

        int getGrade()
        {
            return grade;
        }

        void speak()
        {
            cout<<fname<<": I found a "<<pockets[getNumTrash()-1].name<<"!\n";
        }
        friend ostream& operator<<(ostream& os, const Student &stu)
        {
             os << stu.fname << " " << stu.lname
                << " has iq " << stu.iq
                << " and is at (" << stu.pos.pos_x<< ", "<< stu.pos.pos_y<< ")";
        }


};
#endif // STUDENT_H_INCLUDED
