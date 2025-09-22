/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/ascii-art */

/*
О работе кода:
1. Чтение параметров: l - ширина символа в ASCII art, h - высота символа ASCII art, 
t - текст для преобразования
2. Cохраняем все строки в вектор ascii_rows
3. Переводим текст в верхний регистр
4. Запускаем цикл по высоте строки h, и вложенный - по каждому символу строки для преобразования t: 
4.1) Находим его позицию в алфавите
4.2) Для знака вопроса используем 26 позицию
4.3) Берем соответствующую часть из строки ASCII art
5. Выводим полученную строку
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l; // ширина символа в ASCII art
    cin >> l; cin.ignore();
    int h; // высота символа в ASCII art
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