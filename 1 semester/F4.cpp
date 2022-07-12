#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N , k = 0 , p = 0 ;


    string line_1;

    char mind [1000000];

    char aboba;

    fin >> N;

    for(int i = 0; i < 1000000 ; i++)
    {
        mind[i] = 'Z';
    }

    for(int i = 0; i < N ; i++)
    {
        fin >> aboba >> k >> p ;

        for(int j = k-1 ; j < p ; j++)
        {
            mind[j] = aboba;

        }
    }

     for(int k = 0 ; k < 1000000 ; k++)
     {
         if(line_1.find(mind[k]) == string::npos)
         {
             line_1 += mind[k];
         }
     }

     fout << line_1.size();

    return 0;
}













