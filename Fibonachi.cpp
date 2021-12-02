#include <iostream>
#include <fstream>

using namespace std;

int main() {
 ifstream input ("input.txt");
 ofstream output ("output.txt");
  int n;
  int fn[24] = {0};
  int f0[24] = {0};
  int f1[24] = {0};
 f1[0] = 1;
 cin >> n;
  if (n >= 1)
 cout << "0";
  if (n >= 2)
 cout << " 1";
  for (int i = 1; i < n  ; i++) {
    for (int j = 0; j < 21; j++) {
 fn[j] = f0[j] + f1[j];
    }
    for (int j = 0; j < 21; j++) {
      if (fn[j] >= 10) {

 fn[j+1] += fn[j] / 10;
 fn[j] = fn[j] % 10;
      }
    }
      for (int j = 0; j < 21; j++){
 f0[j] = f1[j];
      }
      for (int j = 0; j < 21; j++){
 f1[j] = fn[j];
      }
cout << " ";
    for (int k = 20; k >= 0; k--) {
        if (fn[k+3] != 0 || fn[k+2] != 0 || fn[k+1] != 0 || fn[k] != 0) {
 cout << fn[k];
        }
      }
  }
}