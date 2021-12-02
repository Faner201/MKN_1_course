#include <iostream>
#include <iomanip>

using namespace  std;

    long double fact(int N)
    {

        if (N == 0)
            return 1;
        if(N < 0)
            return 0;
        else
            return N * fact(N-1);

    }
    int main()
    {
        int N ,answer ;
        cin >> N;

        answer = 1 + (double)(1/fact(N));

        cout << setprecision(5) << fixed <<answer;

    return 0;
}
