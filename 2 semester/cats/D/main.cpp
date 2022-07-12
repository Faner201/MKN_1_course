#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int caterpillarLength = 0;
    int roadLength =  0;
    int time = 0;
    fin >> caterpillarLength >> roadLength;
    queue<int> catarpillar;

    int firstRoad = 0;
    int road = 0;
    fin >> firstRoad;

    int directions[roadLength];
    int elevations = 0;

    for(int i = 0; i < roadLength - 1; i++)
    {
        fin >> road;
        directions[i] = firstRoad < road ? 1 : -1;
        firstRoad = road;
    }
    int j = 0;
    for(j; j < caterpillarLength; j++)
        elevations += directions[j];
    for(j; j < roadLength; j++)
    {
        if(directions[j - 1] == 1 || elevations >= 0)
            time++;
        elevations += directions[j] - directions[j - caterpillarLength];
    }
    fout << time;
}