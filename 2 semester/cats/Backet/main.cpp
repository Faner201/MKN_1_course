#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void BacketSort(vector<string> &lines , int N)
{
    vector<string>intermediateLine[52];

    for(int i = 0 ; i < lines.size() ; i++)
    {
        int k = 0;
        if(lines[i][0] < 91)
            k = 65;
        else
            k = 71;
        int index = lines[i][0] - k;
        intermediateLine[index].push_back(lines[i]);
    }

    for(int i =  0 ; i < 52 ; i++)
    {
        if(!intermediateLine[i].empty())
        {
            for(int j = 0 ; j < intermediateLine[i].size(); j++)
            {
                for (int k = 0; k < intermediateLine[i].size(); i++)
                    for (int l = 0 ;  l < intermediateLine[i].size() - (i + 1) ; l++)
                    {
                        if (intermediateLine[i][l][1] > intermediateLine[i][l+1][1])
                            swap(intermediateLine[i][l], intermediateLine[i][l+1]);
                        else if (intermediateLine[i][l][1] == intermediateLine[i][l+1][1])
                        {
                            if (intermediateLine[i][l][2] > intermediateLine[i][l+1][2])
                                swap(intermediateLine[i][l], intermediateLine[i][l+1]);
                        }
                    }
            }
        }
        else if(intermediateLine[i].empty())
            continue;
    }
    int index = 0;
    for(int i = 0 ; i < 52 ; i++)
    {
        for(int j = 0; j < intermediateLine[i].size(); j++)
            lines[index++] = intermediateLine[i][j];
    }
}

int main()
{

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N = 0;
    string line;
    fin >> N;

    vector<string> lines;

    getline(fin,line);
    for(int i = 0 ; i < N ; i++)
    {
        getline(fin,line);
        lines.push_back(line);
    }


    BacketSort(lines , N);

    for (int i = 0; i < N; i++)
        fout << lines[i] << '\n';

    return 0;
}