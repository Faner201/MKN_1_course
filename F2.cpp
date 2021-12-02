#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool the_score_is_the_same(char same)
{
    const int dip = 6;

    char diphthongs[dip] = {'a', 'e', 'i', 'o', 'u', 'y'};

    for(int i = 0 ; i < dip ; i++)
    {
        if(same == diphthongs[i])
        {
            return true;
        }

    }

    return false;
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line;

    bool biba,boba;

    int N , count = 0 , max = 0;

    fin >> N;

    int*  score = new int[N]{0};

    string* line_1 = new string[N];

    for(int i  = 0; i < N ; i++)
    {
        fin >> line_1[i];
    }

    for(int i = 0 ; i  < N ; i++)
    {
        for(int j = 0 ; j < line_1[i].size() - 1  ; j++)
        {
            biba = the_score_is_the_same(line_1[i][j]);
            boba = the_score_is_the_same(line_1[i][j+1]);

            if(biba && boba)
            {
                if(j>0)
                    biba = the_score_is_the_same(line_1[i][j-1]);
                else biba = false;
                if(j < line_1[i].size() - 1)
                    boba = the_score_is_the_same(line_1[i][j+2]);
                else biba = false;

                if((!biba) && (!boba))
                {
                    count++;
                }
            }
        }
        score[i] = count;
        count = 0;
    }

    for(int l = 0 ; l < N ; l++)
    {
        max = max > score[l] ? max : score[l];
    }

    for(int p = 0 ; p < N ; p++)
    {
        if(max == score[p])
            fout << line_1[p] << '\n';
    }

    return 0;
}











/*for(int h = 0 ; h < dip ; h++ )
           {
               if(line_1[i][j] == diphthongs[h] && line_1[i][j+1] == diphthongs[h])
               {
                   if(j == 0)
                   {
                       if(line_1[i][j+2] != diphthongs[h])
                       {
                           count++;

                       }
                   }
                   if ( j > 0)
                       if((line_1[i][j-1] != diphthongs[h]) && (line_1[i][j+2] !=diphthongs[h]))
                       {
                           count++;

                       }

                   if (j < line_1[i].size() - 1)
                       {
                           if(line_1[i][j-2] != diphthongs[h])
                           {
                               count++;

                           }
                       }
               }
           }*/ //это фигня придумана укропами так что вы можете покопаться здесь и понять как это работает