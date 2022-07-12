#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefixFunction(const string &line)
{
    vector<int> pi(line.length());

    for(int i = 1; i < line.length(); i++)
    {
        int j = pi[i-1];

        while(j > 0 && line[i] != line[j])
            j = pi[j-1];

        if(line[i] == line[j])
            j++;
            pi[i] = j;
    }

    return pi;
}

int main() {
    string line;
    string check;
    bool number = true;


    cin >> check >> line;

    int size  = line.size() * 2 + 1 + check.length();

    vector<int> pi = prefixFunction(check + '#' + line+line);

    for(int i = line.size()+1 ; i < size; i++)
    {
        if(pi[i] == line.length())
        {
            cout << i - line.length() * 2;
            number = true;
            break;
        }
    }

    if(!number)
        cout << "-1";
    return 0;
}