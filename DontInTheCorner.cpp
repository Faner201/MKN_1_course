#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>



using namespace std;

int main() {

    ifstream  fin("input.txt");
    ofstream fout("output.txt");

    double x1 , y1 , x2 , y2 , x , y , centX , centY , OM = 0 , MA = 0 , MB = 0, MC = 0 , MD = 0 , r = 0;

    fin >> x1 >> y1 >> x2 >> y2 >> x >> y;

    centX = (x2 + x1) / 2;

    centY = (y2 + y1) / 2;



    OM = sqrt((pow((x - centX) / 2 , 2)  + (pow((y - centY) / 2, 2))));

    MA = sqrt((pow((x - x1) / 2, 2)) + (pow((y - y1 ) / 2, 2)));
    MB = sqrt((pow((x - x2) / 2 ,2 )) + (pow((y - y1) / 2 , 2 )));
    MC = sqrt((pow((x - x1) / 2 , 2)) + (pow((y - y2)  / 2 , 2)));
    MD = sqrt((pow((x - x2) / 2 , 2)) + (pow((y - y2) / 2 , 2)));

    r = min(min(MA , MB) , min(MC , MD));

    if(r < OM)
    {
        fout << "CORNER";
    }
    else
        fout << "CENTER";








    return 0;
}
