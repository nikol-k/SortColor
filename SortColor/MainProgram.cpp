#include "ColorObject.h"
#include "Functions.h"

int main()
{
    setlocale(LC_ALL, ""); //включаем русские символы
 
    char rule[3], temp_color; //rule - правило сортировки, temp_color - переменная для хранения значения цвета

    int size;
    std::vector <ColorObject> set_of_objects;

    std::cout << "Введите длину вектора ";
    std::cin >> size;

    std::cout << "Введите строку " << std::endl << "Строка должна состоять из 'R', 'G' и 'B': "; //запрос данных  
    for (int i = 0; i < size; i++)
    {
        std::cin >> temp_color;
        set_of_objects.push_back(ColorObject(temp_color));
    }

    std::cout << "Введите правила сортировки." << std::endl << "Для ввода доступны 'R', 'G' иил 'B'." << std::endl;

    CreateRule(rule);//запрос правила сортировки

    Sort(set_of_objects, rule); //запускаем сортировку, передавая вектор и правила сортировки
     
    std::cout << "Результат сортировки:  ";
    for (int i = 0; i < set_of_objects.size(); i++) //выводим результат
    {
        std::cout << set_of_objects[i].GetColor();
    }
}
