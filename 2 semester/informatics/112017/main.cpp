#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <functional>

struct Vector{
    double x;
    double y;
};

double a;
double b;
double c;

Vector gradient(Vector point)
{
    return {
            a * (-8 * (point.y - pow(point.x, 4)) * pow(point.x, 3)) - b * (2 * (1 - point.x)),
            a * (2 * (point.y - pow(point.x, 4))) + c
    };
}

double equation(Vector point)
{
    return a * pow((point.y - pow(point.x,4)),2) + b * pow(1 - point.x,2) + c * point.y;
}

double oneDimensionalFunction(double x, Vector gradient, Vector point, std::function<double(Vector)> const &equation)
{
    Vector buffer = {
            point.x - x * gradient.x,
            point.y - x * gradient.y
    };

    return equation(buffer);
}

double GoldenSelection(double first, double second, double epsilon, Vector gradient, Vector point, std::function<double (Vector)> const &equation)
{
    const double fi = 1.6180339887;

    double x1 = second - ((second - first) / fi);
    double x2 = first + ((second - first) / fi);
    double y1 = oneDimensionalFunction(x1, gradient, point, equation);
    double y2 = oneDimensionalFunction(x2, gradient, point, equation);

    while(fabs(second - first) > epsilon)
    {
        if(y1 <= y2)
        {
            second = x2;
            x2 = x1;
            x1 = second - ((second - first) / fi);
            y2 = y1;
            y1 = oneDimensionalFunction(x1, gradient, point, equation);
        }
        else
        {
            first = x1;
            x1 = x2;
            x2 = first + ((second - first) / fi);
            y1 = y2;
            y2 = oneDimensionalFunction(x2, gradient, point, equation);
        }
    }

    return (first + second) / 2;
}

Vector approximation(Vector point, Vector gradient, double lambda)
{
    Vector buffer = {
            point.x - lambda * gradient.x,
            point.y - lambda * gradient.y
    };

    return buffer;
}



Vector descentDown(Vector point,
                   double epsilon,
                   std::function<double (Vector)> const &equation,
                   std::function<Vector(Vector)> const &gradient)
{
    Vector current = point;
    Vector last{};

    do
    {
        last = current;
        Vector grad = gradient(current);
        double lambda = GoldenSelection(0, 0.01, epsilon, grad, current, equation);
        current = approximation(current, grad, lambda);
    }
    while(fabs(equation(current) - equation(last)) > epsilon);

    return current;
}

//один раз рассчитывается новоя точка x

int main() {
    double epsilon = 1e-10;
    std::cin >> a >> b >> c;
    auto count =  descentDown({1, 1}, epsilon, equation, gradient);
/* while(count != 220)
    {
        descentDown({current.x, current.y}, epsilon, equation, gradient, current);
        count++;
    }*/
    std::cout << std::fixed << std::showpoint << std::setprecision(4);
    std::cout << count.x  << " " << count.y;
    return 0;
}
