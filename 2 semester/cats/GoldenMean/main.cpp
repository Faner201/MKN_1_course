#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void HeapifyUp(int index, vector <int> &array, bool typeHeap)
{
    int root = (index - 1) / 2;
    if(typeHeap && array[index] > array[root] || !typeHeap && array[index] < array[root])
    {
        swap(array[index], array[root]);
        if (root != 0)
            HeapifyUp(root, array, typeHeap);
    }
}

void HeapifyDown(int index, vector <int> &array, bool typeHeap)
{
    int root = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < array.size())
    {
        if(typeHeap && array[left] > array[root] || !typeHeap && array[left] < array[root])
            root = left;
    }

    if(right < array.size())
    {
        if(typeHeap && array[right] > array[root] || !typeHeap && array[right] < array[root])
            root = right;
    }

    if(root != index)
    {
        swap(array[index], array[root]);
        HeapifyDown(root, array, typeHeap);
    }
}

void addElement(int number, vector <int> &array, bool typeHeap)
{
    array.push_back(number);
    HeapifyUp(array.size() - 1, array, typeHeap);
}

void Sift(vector <int> &array, bool typeHeap)
{
    swap(array.front(), array.back());
    array.pop_back();
    HeapifyDown(0, array, typeHeap);
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    vector <int> maxHeap;
    vector <int> minHeap;

    int count;
    input >> count;

    int value;
    input >> value;

    addElement(value, maxHeap, true);
    output << value << ' ';

    for(int i = 1; i < count; i++)
    {
        input >> value;
        if(maxHeap.front() > value)
        {
            addElement(value, maxHeap, true);
            if(maxHeap.size() > minHeap.size() + 1)
            {
                addElement(maxHeap.front(), minHeap, false);
                Sift(maxHeap, true);
            }
        }
        else
        {
            addElement(value, minHeap, false);
            if(minHeap.size() > maxHeap.size())
            {
                addElement(minHeap.front(), maxHeap, true);
                Sift(minHeap, false);
            }
        }
        output << maxHeap.front() << ' ';
    }

    return 0;
}