#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

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

void DFS(vector<vector<int>> &graph,int startPosition, int vertexCount, int *visited)
{
    int count = 1;
    stack<int> current;
    current.push(startPosition);
    visited[startPosition] = 1;
    while(!current.empty())
    {
        startPosition = current.top();
        current.pop();
        for(int i = 0; i < vertexCount; i++)
        {
            if(graph[startPosition][i] == 1 && visited[i] == 0)
            {
                current.push(i);
                visited[i] = 1;
                count++;
            }
        }
    }
    cout << count;
}

void BFS(vector<vector<int>> &graph,int startPosition, int vertexCount, int *visited)
{
    int count = 1;
    queue<int> current;
    current.push(startPosition);
    visited[startPosition] = 1;
    while(!current.empty())
    {
        startPosition = current.front();
        current.pop();
        for(int i = 0; i < vertexCount; i++)
        {
            if(graph[startPosition][i] == 1 && visited[i] == 0)
            {
                current.push(i);
                visited[i] = 1;
                count++;
            }
        }
    }
    cout << count;
}

int main() {
    int vertexCount = 0;
    int startPosition = 0;

    cin >> vertexCount >> startPosition;

    int visited[100] = {0};
    vector<vector<int>> graph(vertexCount, vector<int>(vertexCount));

    AddGraph(graph,vertexCount);

    DFS(graph,startPosition - 1,vertexCount,visited);
    //BFS(graph,startPosition - 1,vertexCount,visited);

    return 0;
}
