/*Формулировка пазла по ссылке https://www.codingame.com/ide/puzzle/max-area*/

/*
О работе кода:
1. Считываем число высот ведра и их самих
2. Поиск максимальной площади
2.1) Начинаем с самых широких границ (левый = 0, правый = n-1)
2.2) Вычисляем площадь: ширина * минимальная высота из двух стенок
2.3) Перемещаем край с меньшей высотой
3. Выводим максимальную площадь
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore(); // очищаем буфер
    
    vector<int> heights(n);  //вектор для хранения введенных высот ведра
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int maxArea = 0; //максимальная площадь
    int left = 0;    //левый край (высота) ведра
    int right = n - 1; // правый край (высота) ведра
    
    // Идем сразу с двух сторон
    while (left < right) {
        // Вычисляем текущую площадь
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int area = width * height;
        
        // Обновляем максимальную площадь
        maxArea = max(maxArea, area);
        
        // Обновляем значение с меньшей высотой
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << maxArea << endl;
    
    return 0;
}