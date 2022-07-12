#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


#define in_min(a,b) (startPoint[a] < startPoint[b] ? (a) : (b))

void AddGraph(int M, vector<vector<int>> &graph, ifstream &fin)
{
    int first, second;
    for(int i = 0; i < M; i++)
    {
        fin >> first >> second;
        graph[first - 1].push_back(second - 1);
        graph[second - 1].push_back(first - 1);
    }
}

void DFS(int startPosition, int father, vector<vector<int>> &graph, int *startPoint, int *up, int timer, vector<int> &answers)
{
    startPoint[startPosition] = ++timer;
    bool flag = false;
    int children = 0;
    for(int childrenId : graph[startPosition])
    {
        if((childrenId != father) && (startPoint[childrenId] < startPoint[startPosition]))
        {
            if(startPoint[childrenId] == 0)
            {
                ++children;
                DFS(childrenId, startPosition, graph, startPoint, up, timer, answers);
                if(startPoint[up[childrenId]] >= startPoint[startPosition])
                    flag = true;
                up[startPosition] = in_min(up[startPosition], up[childrenId]);
            }
            else
                up[startPosition] = in_min(up[startPosition], childrenId );
        }
    }
    if((father == -1) && (children < 2))
        flag = false;
    if(flag)
        answers.push_back(startPosition);
}

int main() {
    int N, M;
    int timer = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> N >> M;
    vector<vector<int>> graph(N);
    vector<int> answers;
    int *startPoint = new int[N]{0};
    int *up = new int[N];
    for(int i = 0; i < N; i++)
        up[i] = i;
    AddGraph(M, graph, fin);
    DFS(0, -1, graph, startPoint, up, timer, answers);
    fout << answers.size();
    for(int num : answers)
        fout << ' ' << num + 1;
    return 0;
}
