#ifndef CAMPUS_H_INCLUDED
#define CAMPUS_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Campus{

    private:
        char area[25][25];
        int campus_size;
        int building_size;

        void buildCampus()
        {
            //Ask Prof Feng if should cast to int
            int trash = (int) floor(0.1 * (campus_size*campus_size - building_size*building_size));
            bool filled = false;
            for(int i=0; i<campus_size; i++)
             {
                for(int j=0; j<campus_size; j++)
                {
                    if (i==building_size-1 && j==building_size-1)
                        area[i][j] = 'D';
                    else if(i<building_size && j<building_size)
                        area[i][j] = 'S';
                        //Ask Prof Feng if this is correct implementation for 10%, or if should put T in certain number of spaces randomly
                    //else if(rand() %10+1 == 1)
                    //    area[i][j] = 'T';
                    else area[i][j] = ' ';
                }
             }
             //if this is correct, ask Prof Feng how to account for missing spaces
            /*
             for(int i=0; i<trash; i++)
                 area[rand() % (campus_size-building_size) + building_size][rand() % (campus_size-building_size) + building_size] = 'T';
            */
            while(!filled)
            {
                int x=rand() % campus_size;
                int y=rand() % campus_size;
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
        Campus(int csize, int bsize)
        {
            bool ok = (bsize < csize && csize < 26);
            if(ok)
            {
                campus_size = csize;
                building_size = bsize;
                buildCampus();
            }
            else
            {
                while(!ok)
                {
                    cout <<"Please make sure the building size is less than the campus size,\n"
                         <<"and that both are less than 25\n"
                         <<"New campus size: ";
                    cin >> csize;
                    cout <<"New building size: ";
                    cin >> bsize;
                    ok = (bsize < csize && csize < 26);
                }
                campus_size = csize;
                building_size = bsize;
                buildCampus();
            }
        }

        int getCampusDimension()
        {
            return campus_size;
        }

        int getBuildingDimension()
        {
            return building_size;
        }

        friend ostream& operator<<(ostream& os, const Campus &camp)
        {
             for(int i=0; i<camp.campus_size; i++)
             {
                for(int j=0; j<camp.campus_size; j++)
                    cout<<camp.area[i][j];
                cout<<"\n";
             }
        }

};
#endif // CAMPUS_H_INCLUDED
