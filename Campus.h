//Jacob Liou CS 1337

using namespace std;
#ifndef CAMPUS_H_INCLUDED
#define CAMPUS_H_INCLUDED
#include "Person.h"
#include "Student.h"
#include "Global.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>


class Campus{

        friend class Student;

    private:
        char area[25][25];
        Dimension bdim;
        Dimension cdim;
        Dimension facPos;
        int trash;

        void buildCampus()
        {
            int trashAmount = (int) floor(0.05 * (cdim.width*cdim.height - bdim.width*bdim.height));
            trash = trashAmount;
            bool filled = false;
            //creating the building
            for(int i=0; i<cdim.width; i++)
             {
                for(int j=0; j<cdim.height; j++)
                {
                    if (i==bdim.width-1 && j==bdim.height-1)
                        area[i][j] = 'D';
                    else if(i<bdim.width && j<bdim.height)
                        area[i][j] = 'B';
                    else area[i][j] = ' ';
                }
             }
            //placing the faculty member
            bool isFac = false;
            while(!isFac)
            {
            int a=(rand() % bdim.width);
            int b=(rand() % bdim.height);

            if(area[a][b] != 'D')
                {
                    area[a][b] = 'F';
                    facPos.width = a;
                    facPos.height = b;
                    isFac = true;
                }
            }
            //placing trash
            while(!filled)
            {
                int x=rand() % cdim.width;
                int y=rand() % cdim.height;
                if(area[x][y] == ' ')
                {
                    area[x][y] = 'T';
                    trashAmount--;
                }
                if(trashAmount == 0)
                    filled = true;
            }
        }

    public:
        Campus(Dimension c, Dimension b)
        {
                bdim = {b.width, b.height};
                cdim = {c.width, c.height};

                //initializing the whole campus to a space so no odd characters pop up
                for(int i=0; i<25; i++)
                {
                    for(int j=0; j<25; j++)
                        {
                            area[i][j] = ' ';
                        }
                }

                buildCampus();

        }
        int numTrash()
        {
            return trash;
        }

        char getCell(Position p)
        {
            return area[p.pos_x][p.pos_y];
        }

        void changeCell(Position p, char c)
        {
            area[p.pos_x][p.pos_y] = c;
        }

        friend ostream& operator<<(ostream& os, const Campus &camp)
        {
             for(int i=0; i<camp.cdim.width; i++)
             {
                for(int j=0; j<camp.cdim.height; j++)
                    cout<<camp.area[i][j];
                cout<<"\n";
             }
        }


};
#endif // CAMPUS_H_INCLUDED
