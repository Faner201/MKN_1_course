#include <iostream>
#include <fstream>

void heapify(int *array, int count, int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < count && array[left] > array[largest])
        largest = left;
    if(right < count && array[right] > array[largest])
        largest = right;
    if(largest != index)
    {
        std::swap(array[index], array[largest]);
        heapify(array,count,largest);
    }
}
void heap(int *array, int count)
{
    for(int i = count / 2 - 1; i >= 0; i--)
        heapify(array,count,i);
}

void changeMax(int *array, int count)
{
    array[0] /= 10;
    heapify(array,count,0);
}

int main() {
    std::ifstream  fin("input.txt");
    int childrenCount, drinkCount;
    fin >> childrenCount >> drinkCount;
    int *thrust = new int [childrenCount];
    for(int i = 0; i < childrenCount; i++)
        fin >> thrust[i];
    heap(thrust,childrenCount);
    for(int i = 0; i < drinkCount; i++)
        changeMax(thrust,childrenCount);
    std::ofstream fout("output.txt");
    uint64_t sum = 0;
    for(int i = 0; i < childrenCount; i++)
    {
        sum += thrust[i];
    }
    fout << sum;
    return 0;
}
