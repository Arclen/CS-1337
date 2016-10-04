//Jacob Liou CS 1337
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Candidate{
    string name;
    char gender;
    double height;
    double weight;
};
int main() {
	fstream file;
	string input;
	int counter = 1;
	int looper = 0;
	Candidate c[40];
	file.open("candidatedata.txt");

        while(file)
        {
            getline(file,input,',');
            /*
            switch(counter)
            {
                case 1:
                    counter++;
                    //c[looper].name = input;
                    break;
                case 2:
                    counter++;
                    //c[looper].gender= atoc(input);
                    break;
                case 3:
                    counter++;
                    //c[looper].height = atof(input);
                    break;
                case 4:
                    counter = 1;
                    //c[looper].weight = atof(input);
                    break;
            }
            looper++;
            std::cout<<input<<std::endl;
            */
            c[looper].name = input;
            looper++;
        }
        for(int i=0; i<40; i++)
        {
            std::cout<<c[i].name;
        }

        file.close();

}
