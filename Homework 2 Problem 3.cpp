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
void getPercentages(Candidate[], int);
void getAvgHeight(Candidate[], int);
void getAvgWeight(Candidate[], int);
void getLightAndHeavy(Candidate[], int);
void getShortAndTall(Candidate[], int);

int main() {
	fstream file;
	string input;
	int counter = 1;
	int looper = 0;
	Candidate *c;
	c = new Candidate[20];
	char temp[10];

	file.open("candidatedata.txt");
    getline(file,input);

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

        getPercentages(c, 20);
        getAvgHeight(c, 20);
        getAvgWeight(c, 20);
        getLightAndHeavy(c, 20);
        getShortAndTall(c, 20);

        delete []c;
}

void getPercentages(Candidate c[], int size)
{
    int females =0;
        float fper;
        for(int i=0; i<size; i++)
        {
            if(c[i].gender=='F')
                females++;
        }
        fper = (float)females/20;
        cout<<"Number of female and male candidates respectively: "<<females<<" "<<20-females;
        cout<<"\nPercentage of female and male candidates respectively: "<<fper<<" "<<(1-fper);
}

void getAvgHeight(Candidate c[], int size)
{
    float mavgH, favgH = 0.0;
        for(int i=0; i<size; i++)
        {
            if(c[i].gender=='F')
                favgH += c[i].height/(size/2);
            else mavgH += c[i].height/(size/2);
        }
        cout<<"\nFemale average height: "<<favgH;
        cout<<"\nMale average height: "<<mavgH;
}

void getAvgWeight(Candidate c[], int size)
{
    float avgW = 0.0;
        for(int i=0; i<size; i++)
        {
            avgW += c[i].weight/size;
        }
        cout<<"\nOverall average weight: "<<avgW;
}

void getLightAndHeavy(Candidate c[], int size)
{
    float minW = 300.0;
        float maxW = 0.0;
        int minloc, maxloc;
        for(int i=0; i<size; i++)
        {
            if(c[i].weight < minW)
            {
                minW = c[i].weight;
                minloc = i;
            }
            if(c[i].weight > maxW)
            {
                maxW = c[i].weight;
                maxloc = i;
            }
        }
        cout<<"\nCandidate with least weight: "<<c[minloc].name<<" "<<c[minloc].gender;
        cout<<"\nCandidate with most weight: "<<c[maxloc].name<<" "<<c[maxloc].gender;
}

void getShortAndTall(Candidate c[], int size)
{
    float shortest = 100.0;
        float tallest = 0.0;
        int shortloc, tallestloc;
        for(int i=0; i<size; i++)
        {
            if(c[i].height < shortest)
            {
                shortest= c[i].height;
                shortloc = i;
            }
            if(c[i].height > tallest)
            {
                tallest = c[i].height;
                tallestloc = i;
            }
        }
        cout<<"\nShortest candidate: "<<c[shortloc].name<<" "<<c[shortloc].gender;
        cout<<"\nTallest candidate: "<<c[tallestloc].name<<" "<<c[tallestloc].gender;
}
