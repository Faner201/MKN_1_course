#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void AddColor(vector<string> &color,int vertexCount)
{
    for(int i = 0; i < vertexCount; i++)
    {
        cin >> color[i];
    }
}

void AddGraph(vector<vector<int>> &graph, int vertexCount)
{
    for(int i = 0;i < vertexCount; i++)
    {
        for(int j = 0;j < vertexCount; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void BFS(vector<vector<int>> &graph,int position, int vertexCount, int *visited,
         vector<string> &color, int &monochrome, int &colorful)
{
    queue<int> current;
    current.push(position);
    visited[position] = 1;
    while(!current.empty())
    {
        position = current.front();
        current.pop();
        for(int i = 0; i < vertexCount; i++)
        {
            if(graph[position][i] == 1)
            {
                if(color[position] == color[i] )
                {
                    monochrome++;
                }
                else
                {
                    colorful++;
                }
                if(visited[i] = 0)
                    current.push(i);
                visited[i] = 1;
            }
        }
    }
}

void Cleaner(int *visited, int vertexCount)
{
    for(int i = 0; i < vertexCount; i++)
        visited[i] = 0;
}

int main() {
    int vertexCount = 0;
    int monochrome = 0;
    int colorful = 0;

    cin >> vertexCount;

    int visited[1000] = {0};
    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));

    vector<string>color(vertexCount);

    AddGraph(graph, vertexCount);
    AddColor(color, vertexCount);

    for(int i = 0; i < vertexCount; i++)
    {
        BFS(graph, i, vertexCount, visited, color, monochrome, colorful);
        Cleaner(visited,vertexCount);
    }

    cout << monochrome / 2 << ' ' << colorful / 2;

    return 0;
}
