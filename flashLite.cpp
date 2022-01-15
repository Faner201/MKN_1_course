#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

fstream  fin("input.txt");
ofstream  fout("output.txt");

int main() {
    int x , y , N , count = 0;
    vector <int> axis(301);

    fin >> N;

    for(int i = 0;i < N ; i++)
    {
        fin >> x >> y;
        for(int j = 100 + x + 1 - y ; j <= (100 + x + y) ; j++) // (100+x + 1 - y это граница левой стороны , мы берём + 1 чтобы засчитать  левую границу ё) а с право берём с права
        {
            axis[j] ++;
        }
    }

    for(int i = 101 ; i < 200;i++)
        count = max(count , axis[i]);
    fout << count;
    return 0;
}
