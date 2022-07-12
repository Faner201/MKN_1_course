#include <iostream>
#include <math.h>

using namespace std;

void Discraminant(double a,double b, double c)
{
    if(b && c)
    {
        double D = (b * b - 4 * a * c);
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b + sqrt(D)) / (2 * a);
        cout << min(x1,x2) << ' ' << max(x1,x2);
    }

    else if (b)
    {
        double x1 = 0;
        double x2 = -b / a;
        cout << min(x1, x2) << ' ' << max(x1, x2);
    }
    else if (c)
    {
        double x = sqrt(-c / a);
        cout << -x << " " << x;
    }
    else
    {
        cout << "0.000 0.000";
    }
}

int main() {
    return 0;
}
