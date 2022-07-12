#include <iostream>
#include <fstream>

#define Infinity INT32_MAX

std::ifstream  fin("input.txt");

void addEdge(int **graph, int vertexCount)
{
    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
        {
            graph[i][j] = Infinity;
        }
        graph[i][i] = 0;
    }
}

void fillingEdge(int **graph, int first, int second, int weight, int edgesCount)
{
    for(int i = 0; i < edgesCount; i++)
    {
        fin >> first >> second >> weight;
        graph[first-1][second-1] = weight;
    }
}

void findingWay(int **graph, int vertexCount)
{
    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
        {
            for(int k = 0;k < vertexCount; k++)
            {
                if(graph[j][i] < Infinity && graph[i][k] < Infinity)
                    graph[j][k] = std::min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
}

void conclusion(int vertexCount, int **graph)
{
    std::ofstream  fout("output.txt");
    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
        {
            if(graph[i][j] != Infinity)
                fout << graph[i][j] << ' ';
            else
                fout << " ";
        }
        fout << '\n';
    }
}

int main() {
    int vertexCount, edgesCount;
    fin >> vertexCount >> edgesCount;

    int **graph = new int *[vertexCount];
    for(int i = 0;i < vertexCount; i++)
    {
        graph[i] = new int [vertexCount];
    }

    addEdge(graph,vertexCount);
    int first, second, weight;
    fillingEdge(graph, first, second, weight, edgesCount);
    findingWay(graph,vertexCount);
    conclusion(vertexCount,graph);
    return 0;
}
