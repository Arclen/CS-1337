#ifndef CAMPUS_H_INCLUDED
#define CAMPUS_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Campus{

    private:
        char area[25][25];
        int campus_size;
        int building_size;

        void buildCampus()
        {
            for(int i=0; i<campus_size; i++)
             {
                for(int j=0; j<campus_size; j++)
                    area[i][j] = 'B';
             }
        }

    public:
        Campus(int csize, int bsize)
        {
            if(bsize < csize && csize < 26)
            {
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

        friend ostream& operator<<(ostream& os, const Campus& camp)
        {
             for(int i=0; i<camp.getCampusDimension(); i++)
             {
                for(int j=0; j<camp.getCampusDimension(); j++)
                    cout<<camp.area[i][j];
                cout<<"\n";
             }
        }

};
#endif // CAMPUS_H_INCLUDED
