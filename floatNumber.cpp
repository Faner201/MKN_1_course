#include <iostream>

using namespace std;

int main() {
    float fnum;
    cin >> fnum;
    if(fnum == 0) {
        cout << 0;
        //return 0;
    }
    else if(fnum < 1e-38 && fnum > -1e-38) {
        cout << -126;
        //return 0;
    }

    int num = *(int*)&fnum;
    cout << ((num >> 23) & 0xff) - 127;
}