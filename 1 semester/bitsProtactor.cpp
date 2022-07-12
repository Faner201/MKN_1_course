#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream  fin("input.txt");
    ofstream  fout("output.txt");

    int a , b , c;

    fin >> a >> b >> c ;

    fout << ((((((a>>2) << 4)^ b) << 1) | c)& 1073741823);// сдвиг на 2 это деление, сдвиг на 4 умножение
    return 0;
}
