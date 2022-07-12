#include <iostream>
#include <vector>
#define MAX 100001

void addGraph(std::vector < std::vector < std::pair < int, int>>> &graph, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int b;
            std::cin >> b;
            if(b != 0)
            {
                graph[i].emplace_back(j, b);
                graph[j].emplace_back(i, b);
            }
        }
    }
}
void addDistance(std::vector<int> &distance, int N, int start)
{
    for(size_t i = 0; i != N; i++)
    {
        distance[i] = MAX;
    }
    distance[start] = 0;
}

void findingWay(std::vector<bool> &checked, std::vector<int> &distance,std::vector<int> &points,
                std::vector < std::vector < std::pair < int, int >>> &graph, int finish, int start, int N)
{
    for(int i = 0; i < N; i++)
    {
        int shortest = -1;
        for(int j = 0; j < N; j++)
        {
            if(!checked[j] && (shortest == -1 || distance[j] < distance[shortest]))
            {
                shortest = j;
            }
        }
        if(distance[shortest] == MAX)
            break;
        checked[shortest] = true;
        for(std::size_t j = 0; j < graph[shortest].size(); j++)
        {
            int up = graph[shortest][j].first;
            int length = graph[shortest][j].second;
            if(distance[shortest] + length < distance[up])
            {
                distance[up] = distance[shortest] + length;
                points[up] = shortest;
            }
        }
    }
    if(distance[finish] == MAX)
    {
        std::cout << 0;
        return;
    }
}
int main() {
    int N, start, finish;
    std::cin >> N;
    std::vector < std::vector < std::pair < int, int >>> graph(N);
    addGraph(graph, N);
    std::cin >> start >> finish;
    start--;
    finish--;
    std::vector < int > distance(N), points(N);
    addDistance(distance, N, start);
    std::vector < bool > checked(N);
    findingWay(checked, distance, points, graph, finish, start, N);
    std::cout << distance[finish] << '\n';

    std::string answer;
    for(int i = finish; i != start; i = points[i])
        answer = std::to_string(i+1) + " " + answer;
    answer = std::to_string(start + 1) + " " + answer;
    std::cout << answer;
    return 0;
}
