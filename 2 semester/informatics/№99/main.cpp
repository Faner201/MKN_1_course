#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefixFunction(const string &line)
{
    vector<int> pi(line.length());

    for(int i = 1; i < line.length() ; i++)
    {
        int j = pi[i-1];

        while(j > 0 && line[i] != line[j])
            j = pi[j-1];

        if(line[i] == line[j])
        {
            pi[i] = j + 1;
        }
        else
            pi[i] = j;
    }

    return pi;
}

int main() {
    string line;
    string check;

    cin >> line >> check;
    auto begin = chrono::steady_clock::now();
    vector<int> pi = prefixFunction(check + '#' + line);
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
    for(int i = 0 ; i < line.length();i++)
    {
        if(pi[check.length() + 1 + i] == check.length())
            cout << i - check.length() + 1 << ' ';
    }
    cout << '\n' << elapsed_ms.count();


    return 0;
}