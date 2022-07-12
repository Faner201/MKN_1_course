#include <iostream>
#include <stack>

using namespace std;

int priority(char symbol)
{
    if(symbol == '+' || symbol == '-')
        return 0;
    else if(symbol == '*' || symbol == '/')
        return 1;
    return -1;
}

int main() {
    stack <char> operations;
    char symbol;
    int number;

    while((symbol = cin.peek()) != '\n')
    {
        if(symbol >= '0' && symbol <= '9')
        {
            cin >> number;
            cout << number << ' ';
        }

        else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            while(!operations.empty() && priority(operations.top()) >= priority(symbol))
            {
                cout << operations.top() << ' ';
                operations.pop();
            }
            operations.push(symbol);
            cin.ignore();
        }
        else if(symbol == '(')
        {
            operations.push(symbol);
            cin.ignore();
        }
        else if(symbol == ')')
        {
            while(operations.top() != '(' )
            {
                cout << operations.top() << ' ';
                operations.pop();
            }
            operations.pop();
            cin.ignore();
        }
    }
    while(!operations.empty())
    {
        cout << operations.top() << ' ';
        operations.pop();
    }
    return 0;
}
