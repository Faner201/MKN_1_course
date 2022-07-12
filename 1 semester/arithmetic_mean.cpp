#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n , count;
    int sum  = 0;
    cin >> n;
    for(int i  = 0 ;i < n ; i++)
    {
        cin >> count ;
        sum += count;
    }

    cout << sum / n ;



    return 0;
}
