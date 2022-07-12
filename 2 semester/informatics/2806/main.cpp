#include <iostream>
#include <cmath>
#include <algorithm>

struct point{
    long long x;
    long long y;

    point(long long x = 0, long long y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

int main() {
    point one, two, three,total;
    std::cin >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y;

    long long a = pow(two.x - one.x, 2) + pow(two.y - one.y, 2);
    long long b = pow(three.x - one.x,2) + pow(three.y - one.y,2);
    long long c = pow(three.x - two.x,2) + pow(three.y - two.y,2);

    if (a > b && a > c)
    {
        total.x = one.x + two.x - three.x;
        total.y = one.y + two.y - three.y;
        std::cout << total.x << ' ' << total.y;
    }
    else if (b > a && b > c)
    {
        total.x = three.x + one.x - two.x;
        total.y = three.y + one.y - two.y;
        std::cout << total.x << ' ' << total.y;
    }
    else
    {
        total.x = three.x + two.x - one.x;
        total.y = three.y + two.y - one.y;
        std::cout << total.x << ' ' << total.y;
    }
    return 0;
}
