#include "ColorObject.h"
#include "Functions.h"

int main()
{
    setlocale(LC_ALL, ""); //�������� ������� �������
 
    char rule[3], temp_color; //rule - ������� ����������, temp_color - ���������� ��� �������� �������� �����

    int size;
    std::vector <ColorObject> set_of_objects;

    std::cout << "������� ����� ������� ";
    std::cin >> size;

    std::cout << "������� ������ " << std::endl << "������ ������ �������� �� 'R', 'G' � 'B': "; //������ ������  
    for (int i = 0; i < size; i++)
    {
        std::cin >> temp_color;
        set_of_objects.push_back(ColorObject(temp_color));
    }

    std::cout << "������� ������� ����������." << std::endl << "��� ����� �������� 'R', 'G' ��� 'B'." << std::endl;

    CreateRule(rule);//������ ������� ����������

    Sort(set_of_objects, rule); //��������� ����������, ��������� ������ � ������� ����������
     
    std::cout << "��������� ����������:  ";
    for (int i = 0; i < set_of_objects.size(); i++) //������� ���������
    {
        std::cout << set_of_objects[i].GetColor();
    }
}