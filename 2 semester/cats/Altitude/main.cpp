#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void aboveRight(int n, int m, int *array, int *right,int *theGap)
{
    for (int i = 0; i < n; i++)
    {
        while (m && array[theGap[m-1]] < array[i])
            right[theGap[--m]] = i;
        theGap[m++] = i;
    }
}

void aboveLeft(int n,int m, int *array, int *left, int *theGap)
{
    for (int i = n-1; i >= 0; i--)
    {
        while (m && array[theGap[m-1]] < array[i])
            left[theGap[--m]] = i;
        theGap[m++] = i;
    }
}

int main()
{

    int n = 0;
    int m = 0;

    cin >> n;

    int array[n];
    int theGap[n];
    int left[n];
    int right[n];


    for (int i = 0; i < n; i++)
        cin >> array[i];

    memset(right, 0xff, sizeof(right));
    aboveRight(n,m,array,right,theGap);

    m = 0;
    memset(left, 0xff, sizeof(left));
    aboveLeft(n,m,array,left,theGap);

    for (int i = 0; i < n; i++) {
        int ans = 0;
        if (left[i] >= 0) ans = i-left[i];
        if (right[i] >= 0 && (right[i]-i < ans || !ans)) ans = right[i]-i;
        cout << ans << ' ';
    }

    return 0;
}