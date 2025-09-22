/*Формулировка пазла по ссылке https://www.codingame.com/training/easy/power-of-thor-episode-1 */

/*
О работе кода:
1. Считываем начальные координаты источника света (lightX, lightY) 
и начальные координаты Тора (initialTX, initialTY)
2. Запускаем бесконечный игровой цикл и считываем оставшееся количество ходов
3. Определем направление движения Тора:
3.1) Сравниваем текущие координаты Тора (currentTX, currentTY) с координатами источника света
3.2) Если Тор находится севернее источника света, нужно двигаться на юг. Если южнее - на север.
3.3) Если Тор находится западнее источника света, нужно двигаться на восток. Если восточнее - на запад.
3.4) Комбинируя эти направления, можем получить юго-западное, северо-восточное и другие комбинации 
4. На каждом шаге выводим направление, в котором должен двигаться Тор 
5. После каждого хода обновляем текущие координаты Тора 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int light_x; // X-координата источника света
    int light_y; // Y-координата источника света
    int initial_tx; // начальная X-координата Тора
    int initial_ty; // начальная Y-координата Тора
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    int current_tx = initial_tx; // текущая X-координата Тора
    int current_ty = initial_ty; // текущая Y-координата Тора

    // игровой цикл
    while (true) {
        int remaining_turns; // оставшееся количество ходов (игнорируем)
        cin >> remaining_turns; cin.ignore();

        string direction = ""; // направление движения

        // Сравниваем текущую позицию Тора с позицией света
        if (current_ty > light_y) {
            direction += "N"; // двигаемся на север
            current_ty--;     // уменьшаем Y-координату
        } else if (current_ty < light_y) {
            direction += "S"; // двигаемся на юг
            current_ty++;     // увеличиваем Y-координату
        }

        if (current_tx > light_x) {
            direction += "W"; // двигаемся на запад
            current_tx--;     // уменьшаем X-координату
        } else if (current_tx < light_x) {
            direction += "E"; // двигаемся на восток
            current_tx++;     // увеличиваем X-координату
        }

        // Выводим направление движения
        cout << direction << endl;
    }
}