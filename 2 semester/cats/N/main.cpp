#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int count = 0;
    int unloading  = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> count >> unloading;
    vector<int> time(count);
    for(int i = 0; i < count; i++)
        fin >> time[i];
    sort(time.begin(),time.end());
    int overexposure = unloading + time[0];
    for(int j = 1;j < count;j++)
    {
        if(time[j] > overexposure)
            overexposure = time[j];
        overexposure += unloading;
    }
    fout << overexposure;
    return 0;
}
