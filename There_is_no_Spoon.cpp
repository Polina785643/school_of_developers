/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Задаем размер сетки
    int width; 
    cin >> width; cin.ignore();
    int height;
    cin >> height; cin.ignore();
    
    // Создаем сетку для хранения клеток
    vector<string> grid;
    for (int i = 0; i < height; ++i) {
        string line;
        getline(cin, line);
        grid.push_back(line);
    }

    // Проходим по всем клеткам сетки
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Если текущая клетка содержит узел (0)
            if (grid[y][x] == '0') {
                // Ищем правого соседа
                int right_x = -1, right_y = -1;  //сначала считаем, что соседа нет
                for (int rx = x + 1; rx < width; ++rx) {
                    if (grid[y][rx] == '0') {
                        right_x = rx;
                        right_y = y;
                        break;
                    }
                }
                
                // Ищем нижнего соседа
                int down_x = -1, down_y = -1; //сначала считаем, что соседа нет
                for (int dy = y + 1; dy < height; ++dy) {
                    if (grid[dy][x] == '0') {
                        down_x = x;
                        down_y = dy;
                        break;
                    }
                }
                
                // Выводим координаты узла и его соседей
                cout << x << " " << y << " " 
                  << right_x << " " << right_y << " " 
                  << down_x << " " << down_y << endl;
            }
        }
    }

    return 0;
}