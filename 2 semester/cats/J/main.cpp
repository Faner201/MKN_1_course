#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
    int first;
    int second;
    int weight;

    bool operator<(const Edge& other)
    {
        return weight < other.weight;
    }
};

void addDSU(int count, int *roots, int *ranks)
{
    for(int i = 0; i < count; i++)
    {
        roots[i] = i;
        ranks[i] = 1;
    }
}

int GetRoot(int value, int* roots)
{
    if(roots[value] == value)
        return value;
    else
        return (roots[value] = GetRoot(roots[value], roots));
}

bool Merge(int first, int second, int* roots, int* ranks)
{
    int firstRoot = GetRoot(first,roots);
    int secondRoot = GetRoot(second,roots);

    if(firstRoot != secondRoot)
    {
        if(ranks[firstRoot] < ranks[secondRoot])
            roots[firstRoot] = secondRoot;
        else if(ranks[secondRoot] < ranks[firstRoot])
            roots[secondRoot] = firstRoot;
        else
        {
            roots[firstRoot] = secondRoot;
            ranks[secondRoot]++;
        }
        return  true;
    }
    return false;
}



int main() {
    int vertexCount, edgesCount;
    std::cin >> vertexCount >> edgesCount;
    std::vector<Edge> graph(edgesCount);
    int *roots = new int[vertexCount + 1];
    int *ranks = new int[vertexCount + 1];
    for(Edge &edge : graph)
        std::cin >> edge.first >> edge.second >> edge.weight;
    std::sort(graph.begin(), graph.end());
    int graphWeight = 0;
    int vertexCountInTree = 1;
    int *dsu = new int[vertexCount + 1];
    addDSU(vertexCount + 1, roots, ranks);
    for(Edge edge : graph)
    {
        if(Merge(edge.first, edge.second, roots, ranks))
        {
            graphWeight += edge.weight;
            vertexCountInTree++;
        }
    }
    if(vertexCount == vertexCountInTree)
        std::cout << graphWeight;
    else
        std::cout << "-1";
    return 0;
}
