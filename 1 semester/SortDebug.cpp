#include <iostream>
#include <fstream>

using namespace std;

void Merg(int *arr , int begin , int end , int n);

void BubleSort(int *arr , int N)
{
    for(int i = 0 ; i < N - 1 ; i++)
    {
        for(int j  = 0 ; j < N - 1 - i ; j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
            }
    }
    if( N == 1)
        return;

    BubleSort(arr,N - 1);
}

void QuickSort(int *arr_1 , int first , int last)
{

    if (first < last)
    {
        int left = first;
        int right = last;
        int middle = arr_1[(left + right) / 2];

        do{
            while(arr_1[left] < middle)
                left++;
            while(arr_1[right] > middle)
                right--;
            if(left <= right)
            {
                swap(arr_1[left] , arr_1[right]);
                left++;
                right--;
            }
        }
        while(left < right);
        QuickSort(arr_1 , first, right);
        QuickSort(arr_1 , left , last);
    }
}

void MergeSort(int *arr , int left , int right  , int n)
{
    if(left < right)
        if(right - left == 1) {
            if(arr[left] > arr[right])
            {
                swap(arr[left] , arr[right]);
            }
        }

        else {
            MergeSort(arr, left, left + (right - left) / 2 , n);
            MergeSort(arr, left + (right - left) / 2 + 1, right , n);
            Merg(arr, left, right , n);
        }

}

void Merg(int *arr , int begin , int end , int n)
{
    int i = begin;
    int mid = begin + (end - begin) / 2;
    int j = mid + 1;
    int k = 0 ;
    int* d =  new int [n];

    while (i <= mid && j <= end){
        if(arr[i] <= arr[j])
        {
            d[k] = arr[i];
            i++;
        }
        else {
            d[k] = arr[j] ;
            j++;
        }

        k++;

    }

    while (i <= mid ) {
        d[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end) {
        d[k] = arr[j];
        j++;
        k++;
    }

    for(int i = 0 ; i < k ; i++)
        arr[begin + i] = d[i];
}

void InsertsSortV1(int *arr , int N)
{
    for(int i = 1; i < N ; i++)
    {
        int k = i;
        while(k != 0 && arr[k] < arr[k - 1])
        {
            swap(arr[k] , arr[k - 1]);
            k--;
        }
    }
    return;
}

void InsertsSortV2(int *arr , int N)
{
    for(int i = 1; i < N ; i++)
    {
        int k = i;
        while(k != 0 && arr[k] > arr[k - 1])
        {
            swap(arr[k] , arr[k - 1]);
            k--;
        }
    }
    return;
}

void conclusion(string SortName , int *arr , int n )
{
    cout << SortName ;

    for(int i = 0  ; i < n ; i++)
        cout << arr[i] << ' ';

    cout << '\n';
}

int main() {

    ifstream fin("input.txt");

    int n , k = 0;

    fin >> n;

    int* ArrSortBuble = new int[n];
    int* ArrSortQuick = new int[n];
    int* ArrSortMerge = new int[n];
    int* ArrInsertsV1 = new int[n];
    int* ArrInsertsV2 = new int[n];

    for(int i = 0 ; i < n ; i++)
    {
        //fin >> ArrSort[i];
        fin >> k;

        ArrSortBuble[i] = ArrSortMerge[i] = ArrSortQuick[i] = ArrInsertsV1[i] = ArrInsertsV2[i] = k;
    }


    BubleSort(ArrSortBuble, n);

    QuickSort(ArrSortQuick , 0 , n - 1);

    MergeSort(ArrSortMerge,0,n-1 , n);

    InsertsSortV1(ArrInsertsV1,n);

    InsertsSortV2(ArrInsertsV2,n);

    conclusion("Bubel sort : " , ArrSortBuble , n);

    conclusion("Quick sort : " , ArrSortQuick , n);

    conclusion("Merge sort : " , ArrSortMerge , n);

    conclusion("Insert sort(from smallest to largest) : " , ArrInsertsV1 , n);

    conclusion("Insert sort(from largest to smallest) : " , ArrInsertsV2 , n);

    return 0;
}
