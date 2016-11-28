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

    private:
        char area[25][25];
        Dimension bdim;
        Dimension cdim;
        int trash;

        void buildCampus()
        {
            trash = (int) floor(0.1 * (cdim.width*cdim.height - bdim.width*bdim.height));
            bool filled = false;
            for(int i=0; i<cdim.height; i++)
             {
                for(int j=0; j<cdim.width; j++)
                {
                    if (i==bdim.height-1 && j==bdim.width-1)
                        area[i][j] = 'D';
                    else if(i<bdim.height && j<bdim.width)
                        area[i][j] = 'S';
                    else area[i][j] = ' ';
                }
             }
            bool isFac = false;
            while(!isFac)
            {
            int a=rand() % bdim.width;
            int b=rand() % bdim.height;
            if(area[a][b] != 'D')
                {
                    area[a][b] = 'F';
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
                    trash--;
                }
                if(trash == 0)
                    filled = true;
            }
        }

    public:
        Campus(Dimension c, Dimension b)
        {
            //bool ok = (b.height < c.height && c.height < 26) && (b.width < c.width && c.width < 26);
            //if(ok)
            //{
                bdim.height=b.height;
                bdim.width=b.width;
                cdim.height=c.height;
                cdim.width=c.width;
                buildCampus();
            //}
        }
        int numTrash()
        {
            return trash;
        }
/*
        int getCampusDimension()
        {
            return cdim.width;
        }

        int getBuildingDimension()
        {
            return bdim.width;
        }
*/


        friend ostream& operator<<(ostream& os, const Campus &camp)
        {
             for(int i=0; i<camp.cdim.width; i++)
             {
                for(int j=0; j<camp.cdim.height; j++)
                    cout<<camp.area[i][j];
                cout<<"\n";
             }
        }

        friend class Student;

};
#endif // CAMPUS_H_INCLUDED
