#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {


    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N,M , count =  0 , index = 0;

    cin >> N  >> M;

    char* number = new char[N];

    bool cum = false;

    char* symbol_source = new char[M];
    char* symbol_a = new char[M];
    char* symbol_b = new char[M];

    for(int i = 0 ; i < N ; i++)
        cin >> number[i];
    for(int i = 0 ; i < M ; i++)
        cin >> symbol_source[i];

    if(N > M)
    {
        cout << 'N';
        return 0;
    }

    for(int i = 0 ; i < N ; i++){
        index += count;
        count = 0;
        for(int j = index ; j < M ; j++ ){

            if(number[i] == '1'){
                if(symbol_source[j] == 'a'){
                    count++;
                    if((N == 1) && (symbol_source[j] != symbol_source[j+1])){
                        cout << 'N';
                        return 0;
                    }
                    if ((count > 0) && (symbol_source[j+1] != 'a'))
                        break;
                }

            }

            if(number[i] == '1'){
                if(symbol_source[j] == 'b'){
                    count++;
                    if((N == 1) && (symbol_source[j] != symbol_source[j+1])){
                        cout << 'N';
                        return 0;
                    }
                    if ((count > 0) && (symbol_source[j+1] != 'b'))
                        break;
                }
            }

            if(number[i] == '0'){
                if(symbol_source[j] == 'a'){
                    count++;
                }
                if ((count > 0) && (symbol_source[j+1] != 'a'))
                    break;
                else{
                    cout << 'N';
                    return 0;
                }
            }

        }
    }
    cout << 'Y';
}
