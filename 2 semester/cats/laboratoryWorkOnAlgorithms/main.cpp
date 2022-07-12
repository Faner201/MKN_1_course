#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void bubbleFlag(int *array, int count)
{
    int c;
    bool flag = true;
    for(int i = 0; (i < count) && flag; i++)
    {
        flag  = false;
        for(int j = 0; j < count - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                c = array[j+1];
                array[j+1] = array[j];
                array[j] = c;
                flag = true;
            }
            c = 0;
        }
    }
}

void merge(uint64_t *arr, uint64_t l, uint64_t m, uint64_t r) {
    uint64_t i, j, k;
    uint64_t n1 = m - l + 1;
    uint64_t n2 = r - m;

    uint64_t *L = new uint64_t [n1], *R = new uint64_t [n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 || j < n2) {
        if (j >= n2 || (i < n1 && L[i] <= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(uint64_t *arr, uint64_t l, uint64_t r) {
    if (l < r) {
        uint64_t m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    uint64_t count = 1e10;

    srand(time(0));

    uint64_t *array = new uint64_t [count];
    for(uint64_t i = 0; i < count; i++)
        array[i] = rand();

    auto start = high_resolution_clock::now();
    mergeSort(array,0,count-1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    uint64_t  time = duration.count();

    cout << '\n' << time;

    return 0;
}
