#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

void AddGraph(vector<vector<int>> &graph, int M)
{
    for(int i = 0; i < M; i++)
    {
        int first,second;
        fin >> first >> second;
        graph[first - 1].push_back(second - 1);
        graph[second - 1].push_back(first - 1);
    }
}

void DFS(vector<vector<int>> &graph, int startPosition)
{
    stack<int> current;
    current.push(0);
    while(!current.empty())
    {
        startPosition = current.top();
        int i;

        for(i = 0; i < graph[startPosition].size(); i++)
        {
            if(graph[startPosition][i] != -1)
            {
                int h = graph[startPosition][i];
                current.push(h);
                graph[startPosition][i] = -1;
                for(int & j : graph[h])
                    if(j == startPosition)
                    {
                        j = -1;
                        break;
                    }
                break;
            }
        }
        if(i == graph[startPosition].size())
        {
            fout << startPosition + 1 << " ";
            current.pop();
        }
    }
}

int main() {
    int N, M,startPosition;
    fin >> N >> M;
    vector<vector<int>> graph(N);
    AddGraph(graph,M);
    for(int i = 0; i < N; i++)
    {
        if(graph[i].size() % 2 != 0)
        {
            fout << "-1";
            return  0;
        }
    }
    DFS(graph,startPosition);
    return 0;
}
