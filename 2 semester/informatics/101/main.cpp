#include <iostream>
#include <string>
#include <vector>

using namespace std;

void IteratingOveRTheDegree (const int alphabet,vector<long long> &alphabetPow)
{
    alphabetPow[0] = 1;
    for(size_t i  = 1; i  < alphabetPow.size(); i++)
    {
        alphabetPow[i] = alphabetPow[i-1] * alphabet;
    }
}

void HashLine(vector <long long> &hashLine,string line,vector<long long> alphabetPow)
{
    for(size_t i = 0 ; i < line.length();i++)
    {
        hashLine[i] = (line[i] - 'a' + 1) * alphabetPow[i];
        if(i)
            hashLine[i] += hashLine[i-1];
    }
}

void HashComparison(long long &hashComparison,string comparison,vector<long long> alphabetPow)
{
    for(size_t i = 0;i < comparison.length();i++)
    {
        hashComparison += (comparison[i] - 'a' + 1) * alphabetPow[i];
    }
}

int main()
{
    const int alphabet = 31;
    string line,comparison;
    cin >> line >> comparison;
    vector<long long> alphabetPow(max (comparison.length(),line.length()));
    vector<long long> hashLine(line.length());
    long long hashComparison = 0;
    long long cur = 0;

    IteratingOveRTheDegree(alphabet,alphabetPow);
    HashLine(hashLine,line,alphabetPow);
    HashComparison(hashComparison,comparison,alphabetPow);

    for(size_t i  = 0; i + comparison.length() - 1 < line.length();i++)
    {
        cur = hashLine[i + comparison.length() - 1];
        if(i)
            cur -= hashLine[i - 1];
        if(cur == hashComparison * alphabetPow[i])
            cout << i << ' ';
    }

}