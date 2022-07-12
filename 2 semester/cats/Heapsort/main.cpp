#include <iostream>
#include <fstream>

using namespace std;

int main() {
//    ifstream fin("heapsort.in");
//    ofstream fout("heapsort.out");
    int count = 0;
    cin >> count;
    int heapsort[count+1];
    for(int i = 1; i < count + 1; i++)
    {
        for(int j = i - 1; j > 1; j /= 2)
            heapsort[j] = heapsort[j/2];
        heapsort[1] = i;
        heapsort[i] = 1;
    }

    for(int i = 1; i < count + 1; i++)
        cout << heapsort[i] << ' ';
    return 0;
}
