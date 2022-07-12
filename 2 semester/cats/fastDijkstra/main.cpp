#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> intPair;

struct Link
{
    int index;
    int weight;

    Link(int weight, int index)
    {
        this->index = index;
        this->weight = weight;
    }
};


void addEdge(int first, int second, int weight, vector<Link> *edges)
{
    edges[first].push_back(Link(weight, second));
}

void shortestPath(int startVertex, int vertexCount, vector<Link> *edges)
{
    priority_queue<intPair, vector<intPair>, greater<intPair>> queue;
    vector<int> distance(vertexCount, INT32_MAX);

    queue.push(make_pair(0, startVertex));
    distance[startVertex] = 0;

    while(!queue.empty())
    {
        int index = queue.top().second;
        queue.pop();

        for(int i = 0; i < edges[index].size(); i++)
        {
            int vertex = edges[index][i].index;
            int weight = edges[index][i].weight;

            if(distance[vertex] > distance[index] + weight)
            {
                distance[vertex] = distance[index] + weight;
                queue.push(make_pair(distance[vertex], vertex));
            }
        }
    }

    ofstream fout("output.txt");

    for(int i = 0; i < vertexCount; i++)
        fout << (distance[i] != INT32_MAX ? distance[i] : -1) << ' ';
}

int main() {
    ifstream fin("input.txt");

    int vertexCount, edgesCount, startVertex;
    fin >> vertexCount >> edgesCount >> startVertex;

    vector<Link> graph[vertexCount];
    int first, second, weight;

    for(int i = 0; i < edgesCount; i++)
    {
        fin >> first >> second >> weight;
        addEdge(first - 1, second - 1, weight, graph);
    }

    shortestPath(startVertex , vertexCount, graph);
    return 0;
}
