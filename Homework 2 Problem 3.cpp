//Jacob Liou CS 1337
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct Candidate{
    string name;
    string gender;
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
    getline(file,input);
        while(file)
        {
            getline(file,input,',');
            std::cout<<input<<std::endl;

            switch(counter)
            {
                case 1:
                    counter++;
                    //c[looper].name = input;
                    break;
                case 2:
                    counter++;
                    //c[looper].gender= input;
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
        }
        file.close();
}
