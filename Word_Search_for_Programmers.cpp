/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/word-search-for-programmers*/

/*
О работе кода:
1. Считываем размер сетки и саму сетку букв, затем строку со словами для поиска
2. Ищем слова в сетке во всех направлениях
2.1) Для каждого слова проверяем 8 возможных направлений (горизонталь, вертикаль, диагонали)
2.2) Сравниваем буквы без учета регистра для корректного поиска
2.3) Если слово найдено, отмечаем все его буквы в матрице найденных позиций
3. Формируем результирующую сетку, оставляя только буквы из найденных слов
3.1) Найденные буквы остаются без изменений
3.2) Остальные буквы заменяются пробелами
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

// Функция для поиска слова в сетке во всех направлениях
void findWord(const vector<string>& grid, const string& word, vector<vector<bool>>& found) {
    int n = grid.size();      // размер сетки (n x n)
    int len = word.length();  // длина искомого слова
    string upperWord = word;  // копия слова для преобразования в верхний регистр

    // Преобразуем слово в верхний регистр для его поиска
    for (int i = 0; i < upperWord.length(); ++i) {
        upperWord[i] = toupper(upperWord[i]);
    }
    
    // Все возможные направления: 8 направлений
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    

    // Перебираем все клетки сетки
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Проверяем все направления из текущей клетки
            for (int dir = 0; dir < 8; ++dir) {
                bool match = true;
                
                // Проверяем все буквы слова в этом направлении
                for (int k = 0; k < len; ++k) {
                    int ni = i + k * dx[dir];
                    int nj = j + k * dy[dir];
                    
                    // Проверяем границы сетки
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
                        match = false;
                        break;
                    }
                    
                    // Проверяем совпадение буквы (без учета регистра)
                    if (toupper(grid[ni][nj]) != upperWord[k]) {
                        match = false;
                        break;
                    }
                }
                
                // Если нашли слово, отмечаем все его позиции
                if (match) {
                    for (int k = 0; k < len; ++k) {
                        int ni = i + k * dx[dir]; // координата y найденной буквы
                        int nj = j + k * dy[dir]; // координата x найденной буквы
                        found[ni][nj] = true;     // отмечаем букву как найденную
                    }
                }
            }
        }
    }
}

int main()
{
    int size; // размер квадратной сетки
    cin >> size; cin.ignore();
    
    vector<string> grid(size); // исходная сетка букв
    for (int i = 0; i < size; i++) {
        getline(cin, grid[i]); // читаем каждую строку сетки
    }
    
    string clues;
    getline(cin, clues);
    
    // Вектор для отметки найденных букв, изначально считаем все false
    vector<vector<bool>> found(size, vector<bool>(size, false));
    
    // Разбиваем слова из clues
    stringstream ss(clues);
    string word; // текущее слово для поиска
    while (ss >> word) {
        // Ищем слово в сетке
        findWord(grid, word, found);
    }
    
    // Строим результат
    for (int i = 0; i < size; i++) {
        string result_row; // результирующая строка для вывода
        for (int j = 0; j < size; j++) {
            if (found[i][j]) {
                result_row += grid[i][j]; // оставляем найденную букву
            } else {
                result_row += ' '; // заменяем ненужную букву пробелом
            }
        }
        cout << result_row << endl;
    }
    
    return 0;
}