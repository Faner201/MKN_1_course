#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line,line_1,line_2 , line_3 , final;

    getline(cin,line);
    getline(cin,line_1);
    getline(cin,line_2);

    bool variable = true;

    int count = 0 , hollow = 0 ;

    for(int i = 0 ; i < line_1.size() ; i++) // если строка S1 равна S2 выводим -1
    {
        if(line_1[i] == line_2[i])
            count++;
    }

    if(count == line_1.size())
    {
        cout << -1;
        return 0;
    }


    while(variable) { // основное тело цикла
        variable = false;

        if(hollow != 0) // перезапись основной строки
        {
            line = final;
            final.clear();
        }
        for(int i = 0 ; i < line.size() ; i++)
        {
            if(i + line_1.size() < line.size() + 1) // проверка что S1 будет меньше S
            {
                count = 0;
                for(int j = 0 ; j < line_1.size() ; j++ )
                {
                    if(line[i+j] == line_1[j]) //проверка на нахождения этого определённого символа в строки S1
                        count++;
                }

                if(count != line_1.size()) // если идёт замена без потери символов в исходной строке то мы просто заменяем иначе
                    //мы в final приписываем S2 и идём уже от -1 элемента над которым мы закончили
                {
                    final += line[i];
                }
                else
                {
                    final += line_2;
                    i += count - 1;
                    variable = true;
                }
            }
            else
                final += line[i];
        }
        hollow++;
    }

    cout << final;



    return 0;
}
