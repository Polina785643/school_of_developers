/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/ascii-art */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l; // ширина символа в ASCII art
    cin >> l; cin.ignore();
    int h; // высота символа
    cin >> h; cin.ignore();
    string t; // строка для преобразования
    getline(cin, t);
    
    // Читаем все строки ASCII art
    vector<string> ascii_rows;
    for (int i = 0; i < h; ++i) {
        string row;
        getline(cin, row);
        ascii_rows.push_back(row);
    }

    // Преобразуем строку в верхний регистр
    transform(t.begin(), t.end(), t.begin(), ::toupper);
    
    // Для каждой строки высоты h
    for (int i = 0; i < h; ++i) {
        string output_line = "";  //для вывода итоговой строки
        
        // Для каждого символа в строке
        for (auto c : t) {
            // Находим позицию символа в алфавите
            int char_index;
            if (c >= 'A' && c <= 'Z') {
                char_index = c - 'A'; // для букв алфавита, начиная c A = 0
            } else {
                char_index = 26; // для доп символа (не буквы, например "?")
            }
            
            // Вычисляем начальную позицию символа в строке ASCII art
            int start_pos = char_index * l;
            
            // Добавляем соответствующую часть строки
            output_line += ascii_rows[i].substr(start_pos, l);
        }
        
        // Выводим строку
        cout << output_line << endl;
    }

    return 0;
}