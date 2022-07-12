#include <iostream>
#include <vector>

struct coordinates{
    int x;
    int y;

    coordinates(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

bool direction(coordinates first, coordinates second)
{
    return (first.x * second.y - first.y * second.x) > 0;
}

void vector(std::vector < std::vector < int > > &point, std::vector < coordinates > &segment, int i)
{
    segment[0].x = point[i][0] - point[i-1][0];
    segment[0].y = point[i][1] - point[i-1][1];

    segment[1].x = point[i+1][0] - point[i][0];
    segment[1].y = point[i+1][1] - point[i][1];
}

void addPoint(int N, std::vector < std::vector < int > > &point)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < 2; j++)
        {
            int count;
            std::cin >> count;
            point[i].push_back(count);
            if(i == 0 )
                point[N].push_back(count);
            if(i == 1)
                point[N+1].push_back(count);
        }
    }
}

int main() {
    int N, tru = 0, fol = 0;
    std::cin >> N;
    std::vector < std::vector < int > > point(N + 2);
    std::vector < coordinates > segment(2);
    addPoint(N, point);
    for(int i = 1; i <= N; i++)
    {
        vector(point, segment, i);
        if(direction(segment[0], segment[1]))
        {
            tru += 1;
        }
        else
        {
            fol += 1;
        }
    }

    if(tru == N || fol == N)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}
