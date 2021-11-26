#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream  fout("output.txt");

    int x,k , a;

    fin >> x >> k;

    if(pow(2,k) > x)
    {
        fout << '0';
    }
    else
    {
        x  = (x >> k) & 1;
        fout << x;


    }


    

    return 0;
}
