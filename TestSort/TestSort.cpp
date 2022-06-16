#include "pch.h"
#include "CppUnitTest.h"
#include "../SortColor/ColorObject.h"
#include "../SortColor/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//создаЄм экземпл€р класса из строки
void StrToClass(std::vector<ColorObject>& objects_no_sort, std::string no_sort, int n)
{
	for (int i = 0; i < n; i++)
	{
		objects_no_sort.push_back(ColorObject(no_sort[i]));
	}
}

//преобразование экземпл€ра класса в строку
void ClassToStr(std::vector< ColorObject> objects_no_sort, std::string& ch_object_sort, int n)
{
	for (int i = 0; i < n; i++)
	{
		ch_object_sort[i] = objects_no_sort[i].GetColor();
	}
}


namespace TestSort
{
	TEST_CLASS(TestSort)
	{
	public:

		TEST_METHOD(TestValid)//тест полностью корректной строки
		{
			std::vector <ColorObject> objects_no_sort; //создаЄм экземпл€р класса

			/*
			создаЄм 3 строки:
			no_sort-начальный неотсортированный вектор
			sort - предпологаемый результат сортировки
			ch_object_sort - переменна€ дл€ преобразовани€ экземпл€ра класса в строку
			*/
			std::string no_sort = "RGGRBGB", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7); //создаЄм экземпл€р класса из строки

			Sort(objects_no_sort, "RGB");//запуск сортировки с заданым правилом

			ClassToStr(objects_no_sort, ch_object_sort, 7);//преобразование экземпл€ра класса в строку

			Assert::AreEqual(ch_object_sort, sort);//проверка, что результат сортировки равен ожидаемому результату
		}

		TEST_METHOD(TestInValid)//тест полностью некорректной строки
		{
			std::vector <ColorObject> objects_no_sort;

			/*
			создаЄм 3 строки:
			no_sort-начальный неотсортированный вектор
			sort - предпологаемый результат сортировки
			ch_object_sort - переменна€ дл€ преобразовани€ экземпл€ра класса в строку
			*/
			std::string no_sort = "rggrbgb", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7);//создаЄм экземпл€р класса из строки

			Sort(objects_no_sort, "RGB");//запуск сортировки с заданым правилом

			ClassToStr(objects_no_sort, ch_object_sort, 7);//преобразование экземпл€ра класса в строку

			Assert::AreNotEqual(ch_object_sort, sort);//проверка, что результат сортировки Ќ≈ равен ожидаемому результату
		}

		TEST_METHOD(TestInCorrect)//тест строки, содержащий "лишние" элементы
		{
			std::vector <ColorObject> objects_no_sort;

			/*
			создаЄм 3 строки:
			no_sort-начальный неотсортированный вектор
			sort - предпологаемый результат сортировки
			ch_object_sort - переменна€ дл€ преобразовани€ экземпл€ра класса в строку
			*/
			std::string no_sort = "R GGR BG B", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7);//создаЄм экземпл€р класса из строки

			Sort(objects_no_sort, "RGB");//запуск сортировки с заданым правилом

			ClassToStr(objects_no_sort, ch_object_sort, 7);//преобразование экземпл€ра класса в строку

			Assert::AreEqual(ch_object_sort, sort);//проверка, что результат сортировки равен ожидаемому результату
		}
	};
}