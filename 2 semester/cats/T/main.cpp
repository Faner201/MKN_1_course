#include <iostream>
#include <vector>

typedef std::pair<int, int> ipair;

////// Edge -> x
void EdgeCreateFromEdges(int vertexCount, std::vector<ipair> *edges)
{
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    edges = new std::vector<ipair>(edgesCount);
    for(auto &edge : *edges)
    {
       std::cin >> edge.first;
       std::cin >> edge.second;
    }
}

void EdgeCreateFromList(int vertexCount, std::vector<ipair> *edges)
{
    edges = new std::vector<ipair>();
    std::cin >> vertexCount;

    int count;
    for(int i = 1; i <= vertexCount; i++)
    {
        std::cin >> count;
        int number;
        for(int j = 0; j < count; j++)
        {
            std::cin >> number;
            edges->push_back(std::make_pair(i, number));
        }
    }
}

void EdgeCreateFromMatrix(int vertexCount, std::vector<ipair> *edges)
{
//    edges = new std::vector<ipair>();
    std::cin >> vertexCount;

    bool connected;
    for(int i = 1; i <= vertexCount; i++)
    {
        for(int j = 1; j <= vertexCount; j++)
        {
            std::cin >> connected;
            if(connected)
                edges->push_back(std::make_pair(i, j));
        }
    }
}

void EdgeShow(int vertexCount, std::vector<ipair> *edges)
{
    std::cout << vertexCount << ' ' << edges->size() << '\n';
    for(auto &edge : *edges)
        std::cout << edge.first << ' ' << edge.second << '\n';
}
//////

///// List -> x

void ListCreateFromEdges(int vertexCount, std::vector<int> *list)
{
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    list = new std::vector<int>[vertexCount];

    int first, second;
    for(int i = 0; i < edgesCount; i++)
    {
        std::cin >> first >> second;
        list[first - 1].push_back(second);
    }
}

void ListCreateFromLists(int vertexCount, std::vector<int> *list)
{
    std::cin >> vertexCount;
    list = new std::vector<int>[vertexCount];

    int edgesCount;
    for(int i = 0; i < vertexCount; i++)
    {
        std::cin >> edgesCount;
        int number;
        for(int j = 0; j < edgesCount; j++)
        {
            std::cin >> number;
            list[i].push_back(number);
        }
    }
}

void ListCreateFromMatrix(int vertexCount, std::vector<int> *list)
{
    std::cin >> vertexCount;
    list = new std::vector<int>[vertexCount];

    bool connected;
    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 1; j <= vertexCount; j++)
        {
            std::cin >> connected;
            if(connected)
                list[i].push_back(j);
        }
    }
}

void ListShow(int vertexCount, std::vector<int> *list)
{
    std::cout<< vertexCount << '\n';
    for(int i = 0; i < vertexCount; i++)
    {
        std::cout << list[i].size() << ' ';
        for(auto &vertex : list[i])
        {
            std::cout << vertex << ' ';
        }
        std::cout << '\n';
    }
}
//////

////// Matrix -> x

void MatrixCraateFromEdges(int vertexCount, bool **matrix)
{
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    matrix = new bool*[vertexCount];
    for(int i = 0; i < vertexCount; i++)
        matrix[i] = new bool[vertexCount]{0};

    int first, second;
    for(int i = 0; i < edgesCount; i++)
    {
        std::cin >> first >> second;
        matrix[first - 1][second - 1] = true;
    }
}

void MatrixCreateFromList(int vertexCount, bool **matrix)
{
    std::cin >> vertexCount;
    matrix = new bool*[vertexCount];
    for(int i = 0; i < vertexCount; i++)
        matrix[i] = new bool[vertexCount]{0};

    int edgesCount;
    for(int i = 0; i < vertexCount; i++)
    {
        std::cin >> edgesCount;
        int number;
        for( int j = 0; j < edgesCount; j++)
        {
            std::cin >> number;
            matrix[i][number - 1] = true;
        }
    }
}

void MatrixCreateFromMatrix(int vertexCount, bool **matrix)
{
    std::cin >> vertexCount;
    matrix = new bool*[vertexCount];
    for(int i = 0; i < vertexCount; i++)
        matrix[i] = new bool[vertexCount]{0};

    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
            std::cin >> matrix[i][j];
    }
}

void MatrixShow(int vertexCount, bool **matrix)
{
    std::cout << vertexCount << '\n';
    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}

//////

int main() {
    int vertexCount;
    bool **matrix;
    std::vector<int> list;
    std::vector<ipair> edges;
    std::string start, end;

    std::cin >> start >> end;
    if(start == "edges" and end == "edges")
    {
        EdgeCreateFromEdges(vertexCount, &edges);
        EdgeShow(vertexCount, &edges);
    }
    else if(start == "edges" and end == "lists")
    {
        EdgeCreateFromList(vertexCount, &edges);
        EdgeShow(vertexCount, &edges);
    }
    else if(start == "edges" and end == "mat")
    {
        EdgeCreateFromMatrix(vertexCount, &edges);
        EdgeShow(vertexCount, &edges);
    }
    return 0;
}
