#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    Graph()
    {
        connections = new vector<vector<int>>();
    }

    void AddConecctions(int number, vector<int> first)
    {
        connections[number].push_back(first);
    }
    void ConclusionConnections(int first,int number)
    {
       cout << connections[number][first] << ' ';
    }

private:
    vector<vector<int>> *connections;
};

int main() {
    int edgesCount, startVertex;
    cin >> edgesCount >> startVertex;
    Graph graph;
    int first, second, weigth;
    for(int i = 0; i < edgesCount; i++)
    {
        cin >> first >> second >> weigth;
    }

    for(int i = 0;i < edgesCount; i++)
    {

    }
    return 0;
}
