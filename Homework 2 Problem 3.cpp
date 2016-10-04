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
	Candidate c[100];
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
        for(int i=0; i<100; i++)
        {
            std::cout<<"\n"<<c[i].name<<" "<<c[i].gender<<" "<<c[i].height<<" "<<c[i].weight<<"\n";
        }

}
