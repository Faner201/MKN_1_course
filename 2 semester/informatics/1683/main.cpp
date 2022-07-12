#include <iostream>
#include <vector>

bool kuhn(std::vector < std::vector < int > > &graph, std::vector < char > &matching,
          std::vector < int > top, int currentTop);

void addGraph(std::vector < std::vector < int > > &graph, int N, int S)
{
    for(int i = 0; i < S; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int count;
            std::cin >> count;
            if(count)
                graph[i].push_back(count);
        }
    }
}

void extender(int pin, std::vector < char > &matching, int S,std::vector < int > &top,
              std::vector< std::vector < int > > &graph)
{
    for(int i = 0; i < S; i++)
    {
        matching.push_back(false);
        pin += kuhn(graph, matching, top, i);
    }
    std::cout << pin;
}

bool kuhn(std::vector < std::vector < int > > &graph, std::vector < char > &matching,
          std::vector < int > top, int currentTop )
{
    if(matching[currentTop])
        return false;
    matching[currentTop] = true;

    for(size_t i = 0; i < graph[currentTop].size(); i++)
    {
        int to = graph[currentTop][i];
        if((top[to] == -1 || top[to-1] == -1) || kuhn(graph, matching, top, top[to]))
        {
            top[to] = currentTop;
            return true;
        }
    }
    return false;
}

int main() {
    int N, S;
    std::cin >> N >> S;
    std::vector < std::vector < int > > graph(S);
    addGraph(graph, N, S);
    std::vector < int > top(N, -1);
    std::vector < char > matching(S);
    int pin = 0;
    extender(pin, matching, S, top, graph);
    return 0;
}