#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

bool isoperation(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int priority(char symbol)
{
    if(symbol == '+' || symbol == '-')
        return 0;
    if(symbol == '*' || symbol == '/')
        return 1;
    return -1;
}

long long score(double sec , double fir , char operations)
{
    if(operations == '+')
        return (long long)(fir + sec);
    if(operations == '-')
        return (long long)(fir - sec);
    if(operations == '*')
        return (long long)(fir * sec);
    if(operations == '/')
        return floor(fir / sec);
}

class Base {
public:
    long long sec  , fir;
    char operations;
};

Base Handler(stack<double> &numbers , stack<char> &operation)
{
    Base pos;

    pos.sec = numbers.top();
    numbers.pop();
    pos.fir = numbers.top();
    numbers.pop();
    pos.operations = operation.top();
    operation.pop();

    return pos;

}

int main() {
    char symbol;
    stack<char> operation;
    stack<double> numbers;
    Base result;

    while ((symbol = cin.peek()) != '\n') {
        if (isdigit(symbol)) {
            long long number;
            cin >> number;
            numbers.push(number);
            continue;
        }
        else if (isoperation(symbol)) {
            while (!operation.empty() && operation.top() != '(' &&
                priority(symbol) <= priority(operation.top()))
            {
                result = Handler(numbers, operation);
                numbers.push(score(result.sec, result.fir, result.operations));

            }
            operation.push(symbol);
        }
        else if (symbol == '(')
        {
            operation.push(symbol);
        }
        else if (symbol == ')') {
            while (operation.top() != '(') {
                result = Handler(numbers, operation);
                numbers.push(score(result.sec, result.fir, result.operations));
            }
            operation.pop();
        }

        cin.ignore();
    }

    while(!operation.empty())
    {
        result = Handler(numbers , operation);
        numbers.push(score(result.sec,result.fir,result.operations));
    }

    cout << (long long)numbers.top();
    return 0;
}