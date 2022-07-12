#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> * graph;
int * visited;
int * answer;
int ans_size = 0;
bool cycle = false;

std::ifstream fin("input.txt");

void DFS(int startPosition)
{
    visited[startPosition] = 1;
    for(int i : graph[startPosition])
    {
        if (visited[i] == 0)
            DFS(i);
        else if (visited[i] == 1) {
            cycle = true;
            return;
        }
    }
    answer[ans_size++] = startPosition;
    visited[startPosition] = 2;
}

void AddGraph(int m)
{
    for(int i = 0; i < m; i++)
    {
        int a,b;
        fin >> a >> b;
        graph[a-1].push_back(b-1);
    }
}

int main() {
    int n, m;

    std::ofstream fout("output.txt");

    fin >> n >> m;
    visited = new int[n]{0};
    answer = new int[n];
    graph = new std::vector<int>[n];
    AddGraph(m);
    for(int i = 0; i < n; i++)
        if(!visited[i])
            DFS(i);
    for(int i = 0; i < n/2; i++)
        std::swap(answer[i], answer[n - i - 1]);
    if (cycle)
        fout << "-1";
    else
        for(int i = 0; i < ans_size; i++)
            fout << answer[i] + 1 << ' ';

    return 0;
}
