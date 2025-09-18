/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/temperatures */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
    int n; // количество температур для анализа
    cin >> n; cin.ignore();
    
    // Проверка на нулевую строку
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int closest; // ближайшая к 0 температура
    string line; //строка со всеми температурами 
    getline(cin, line); // читаем сразу всю строку с температурами
    
    stringstream ss(line); // создаем поток из строки с температурами
    int current; // конкертное значение температуры в цикле
    ss >> closest; // первая введеная температура становится начальным значением closest
    
    // Цикл по строке с температурами 
    while (ss >> current) { // читаем числа из потока
        if (abs(current) < abs(closest)) {
            closest = current;
        }
        else if (abs(current) == abs(closest)) {
            // приоритетно выбираем положительные числа в случае равенства по модулю
            if (current > 0) {
                closest = current;
            }
        }
    }
    
    cout << closest << endl;
    return 0;
}