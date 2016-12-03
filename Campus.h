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
            int trashAmount = (int) floor(0.35 * (cdim.width*cdim.height - bdim.width*bdim.height));
            trash = trashAmount;
            bool filled = false;
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
                bdim.height=b.height;
                bdim.width=b.width;
                cdim.height=c.height;
                cdim.width=c.width;

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
