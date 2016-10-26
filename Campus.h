#ifndef CAMPUS_H_INCLUDED
#define CAMPUS_H_INCLUDED
#include <string>
#include <stdlib.h>
using namespace std;

class Campus{

    private:
        char area[][];
        int campus_size;
        int building_size;

        void buildCampus()
        {

        }

    public:
        Campus(int csize int bsize)
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


};
#endif // CAMPUS_H_INCLUDED
