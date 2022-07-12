#include <iostream>
#include <vector>
#include <set>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> minTopologicalSort(vector<vector<int>> &graph, vector<int> &visited)
{
    vector<int> answer;
    set<int>zero, first; //множество единиц и нулей

    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == 0)
            zero.insert(i); // добавление в множество i-ого элемента
    }

    while(!zero.empty())
    {
        int startPosition = *zero.begin();
        zero.erase(zero.begin()); // уничтожение первого элемента в этом контейнере
        answer.push_back(startPosition);
        for(int i : graph[startPosition])
        {
            visited[i]--;
            if(visited[i] == 0)
                first.insert(i);
        }
        if(zero.empty())
        {
            copy(first.begin(), first.end(), inserter(zero, zero.begin()));
            first.clear();
        }
    }
    return  answer;
}

void AddGraph(int m, vector<vector<int>> &graph, vector<int> &visited)
{
    for(int i = 0; i < m;i++)
    {
        int a, b;
        fin >> a >> b;
        graph[--a].push_back(--b);
        visited[b]++;

    }
}

int main() {
    int n,m;
    fin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> visited(n);
    AddGraph(m, graph, visited);
    vector<int> answer = minTopologicalSort(graph, visited);
    for(int i : answer)
        fout << i+1 << ' ';
    return 0;
}
