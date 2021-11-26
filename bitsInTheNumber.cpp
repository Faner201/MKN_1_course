#include <iostream>
#include <fstream>

using namespace std;
int main() {

    int i , n;

    cin >> n >> i;

    n |= (1 << i);

    cout << n;

    return 0;
}
