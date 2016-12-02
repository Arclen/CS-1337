//Jacob Liou CS 1337
/*
Optionals:
-included speak() function
*/
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
        int grade;
        Trash pockets[10];


    public:
        Student()
        {
            fname = "Bob";
            lname = "Doherty";
            iq = rand() % 20 + 50;
            pos.pos_x = 0;
            pos.pos_y = 0;

            for(int i=0; i<10; i++)
            {
                pockets[i].removeTrash();
                //cout<<pockets[i];
            }
        }

        Student(string f, string l, int q)
        {
            fname = f;
            lname = l;
            //pos.pos_x = p.pos_x;
            //pos.pos_y = p.pos_y;
            pos.pos_x = 0;
            pos.pos_y = 0;
            iq = q;

            for(int i=0; i<10; i++)
            {
                pockets[i].removeTrash();
                //cout<<pockets[i];
            }
        }

        void go_to_campus(Campus& c)
        {
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
            else c.area[pos.pos_x][pos.pos_y];
            //cout<<"go_to_campus debug";
        }

        void setIQ(int i)
        {
            iq = i;
        }

        int getIQ()
        {
            return iq;
        }

        void move(Campus& c)
        {
            if (c.numTrash() == 0)
            {
                /*int x=rand() % c.cdim.width;
                int y=rand() % c.cdim.height;
                c.area[x][y]='G';*/
                c.area[pos.pos_x][pos.pos_y] = ' ';
                int diffX = pos.pos_x - c.bdim.width;
                int diffY = pos.pos_y - c.bdim.height;

                if(diffX == diffY)
                {
                    pos.pos_x--;
                    pos.pos_y--;
                }
                else if(diffX == 0 && diffY > 0)
                    pos.pos_y--;
                else if(diffX == 0 && diffY < 0)
                    pos.pos_y++;
                else if(diffX > 0 && diffY == 0)
                    pos.pos_x--;
                else if(diffX < 0 && diffY == 0)
                    pos.pos_x++;
                else if (diffX > 0 && diffY < 0)
                    {
                        pos.pos_x--;
                        pos.pos_y++;
                    }
                else if(diffX < 0 && diffY > 0)
                    {
                        pos.pos_x++;
                        pos.pos_y--;
                    }
                if(c.area[pos.pos_x][pos.pos_y] == 'D')
                    cout<<"AT DOOR";
                c.area[pos.pos_x][pos.pos_y] = 'S';
                //cout<<"move debug\n";


            }
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
                if(c.area[pos.pos_x][pos.pos_y] == 'T')
                {
                    int index = getNumTrash();
                    pockets[index] = Trash();
                    if(pockets[index].name == "bomb")
                    {
                        iq -= 2;
                        cout<<"BOOM!\n";
                        pockets[index].removeTrash();
                    }
                    else speak();
                    c.trash--;
                    c.area[pos.pos_x][pos.pos_y] = 'S';
                    grade += pockets[index].value;

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
