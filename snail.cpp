#include <iostream>

using namespace  std;

int main()
{
    int h, a,  b , days , statick;

    cin >> h >> a >> b;

    statick = a;
    days = 1;

    while (a < h)
    {

        a -= b;
        days++;
        a += statick;
    }

    cout << days;

    return 0;
}
