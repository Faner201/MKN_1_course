#include <iostream>
#include <cmath>
#include <iomanip>

struct point{
    double x;
    double y;
};

int main() {
    point point;
    double A, B, C;
    std::cin >> point.x >> point.y >> A >> B >> C;
    double d = abs(A * point.x + B * point.y + C) / sqrt(pow(A,2) + pow(B, 2));
    std::cout << std::setprecision(5) << std::fixed  << d;
    return 0;
}
