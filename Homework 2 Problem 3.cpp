//Jacob Liou CS 1337
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
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
	Candidate c[20];
	char temp[100];
	file.open("candidatedata.txt");
        while(!file.eof())
        {
            getline(file,input,',');
            c[looper].name=input;

            getline(file,input,',');
            strcpy(temp,input.c_str());
            c[looper].gender=temp[0];

            getline(file,input,',');
            strcpy(temp,input.c_str());
            c[looper].height=atof(temp);

            getline(file,input);
            strcpy(temp,input.c_str());
            c[looper].weight=atof(temp);

            looper++;
        }
        file.close();
        /*for(int i=0; i<20; i++)
        {
            std::cout<<"\n"<<c[i].name<<" "<<c[i].gender<<" "<<c[i].height<<" "<<c[i].weight<<"\n";
        }*/
        int females =0;
        float fper;
        for(int i=0; i<20; i++)
        {
            if(c[i].gender=='F')
                females++;
        }
        fper = (float)females/20;
        std::cout<<"Number of female and male candidates respectively: "<<females<<" "<<20-females;
        std::cout<<"\nPercentage of female and male candidates respectively: "<<fper<<" "<<(1-fper);

}
