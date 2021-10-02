#include <iostream>
using namespace std;

int main() {
    int hours,minets,second;

    cin >> hours >> minets;

    second = (86400 -((hours * 3600) + (minets * 60)));

    cout << second / 3600 << ' ' << 60 - minets;

    return 0;
}
