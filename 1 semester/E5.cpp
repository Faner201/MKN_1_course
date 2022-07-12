#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int N, k = 0,a = 0 ;

    fin >> N;

    for (int i = 1; i < N + 1;i++) {
        if (i == 1) {
            for (int j = 1; j < N + 1; j++) {

                fout << j << ' ';
                k = j;

            }

            a = k;
            fout << '\n';

        }

        else if (i % 2 == 0) {
            for (int j = a+N; j > a; j--) {

                fout << j << ' ';
                k = j;

            }

            a = k;
            fout << '\n';

        }

        else
        {
            for (int j = N + a;j < (2 * N) + a; j++) {

                fout << j << ' ';
                k = j;

            }

            a = k;
            fout << '\n';

        }

    }
    return 0;

}