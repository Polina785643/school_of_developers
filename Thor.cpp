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