#include <iostream>
#include <fstream>
#define Infinity INT32_MAX

std::ifstream fin("input.txt");
struct Edge
{
    int first;
    int second;
    int weight;
};

void addEdge(Edge *graph, int edgesCount)
{
    for(int i = 0; i < edgesCount; i++)
    {
        fin >> graph[i].first;
        graph[i].first--;
        fin >> graph[i].second;
        graph[i].second--;
        fin >> graph[i].weight;
    }
}

void addWay(int *road, int vertexCount, int startVertex)
{
    for(int i = 0; i < vertexCount; i++)
        road[i] = Infinity;
    road[startVertex - 1] = 0;
}

void findingWay(int *road, int vertexCount, int edgesCount, Edge *graph)
{
    for(int i = 0; i < vertexCount - 1; i++)
    {
        for(int j = 0; j < edgesCount; j++)
        {
            if(road[graph[j].first] < Infinity)
            {
                int sum = road[graph[j].first] + graph[j].weight;
                if (sum < road[graph[j].second])
                    road[graph[j].second] = sum;
            }
        }
    }
}

void conclusion(int *road, int vertexCount)
{
    std::ofstream fout("output.txt");
    for(int i = 0; i < vertexCount; i++)
    {
        if(road[i] != Infinity)
            fout << road[i] << ' ';
        else
            fout << " ";
    }
}
int main() {
    int  vertexCount, edgesCount, startVertex;
    std::cin >> vertexCount >> edgesCount >> startVertex;

    Edge *graph = new Edge [edgesCount];
    int *road = new int [vertexCount];

    addEdge(graph, edgesCount);
    addWay(road, vertexCount, startVertex);
    findingWay(road, vertexCount, edgesCount, graph);
    conclusion(road, vertexCount);

    return 0;
}
