#include "pch.h"
#include "CppUnitTest.h"
#include "../SortColor/ColorObject.h"
#include "../SortColor/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//������ ��������� ������ �� ������
void StrToClass(std::vector<ColorObject>& objects_no_sort, std::string no_sort, int n)
{
	for (int i = 0; i < n; i++)
	{
		objects_no_sort.push_back(ColorObject(no_sort[i]));
	}
}

//�������������� ���������� ������ � ������
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

		TEST_METHOD(TestValid)//���� ��������� ���������� ������
		{
			std::vector <ColorObject> objects_no_sort; //������ ��������� ������

			/*
			������ 3 ������:
			no_sort-��������� ����������������� ������
			sort - �������������� ��������� ����������
			ch_object_sort - ���������� ��� �������������� ���������� ������ � ������
			*/
			std::string no_sort = "RGGRBGB", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7); //������ ��������� ������ �� ������

			Sort(objects_no_sort, "RGB");//������ ���������� � ������� ��������

			ClassToStr(objects_no_sort, ch_object_sort, 7);//�������������� ���������� ������ � ������

			Assert::AreEqual(ch_object_sort, sort);//��������, ��� ��������� ���������� ����� ���������� ����������
		}

		TEST_METHOD(TestInValid)//���� ��������� ������������ ������
		{
			std::vector <ColorObject> objects_no_sort;

			/*
			������ 3 ������:
			no_sort-��������� ����������������� ������
			sort - �������������� ��������� ����������
			ch_object_sort - ���������� ��� �������������� ���������� ������ � ������
			*/
			std::string no_sort = "rggrbgb", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7);//������ ��������� ������ �� ������

			Sort(objects_no_sort, "RGB");//������ ���������� � ������� ��������

			ClassToStr(objects_no_sort, ch_object_sort, 7);//�������������� ���������� ������ � ������

			Assert::AreNotEqual(ch_object_sort, sort);//��������, ��� ��������� ���������� �� ����� ���������� ����������
		}

		TEST_METHOD(TestInCorrect)//���� ������, ���������� "������" ��������
		{
			std::vector <ColorObject> objects_no_sort;

			/*
			������ 3 ������:
			no_sort-��������� ����������������� ������
			sort - �������������� ��������� ����������
			ch_object_sort - ���������� ��� �������������� ���������� ������ � ������
			*/
			std::string no_sort = "R GGR BG B", sort = "RRGGGBB", ch_object_sort = "0000000";

			StrToClass(objects_no_sort, no_sort, 7);//������ ��������� ������ �� ������

			Sort(objects_no_sort, "RGB");//������ ���������� � ������� ��������

			ClassToStr(objects_no_sort, ch_object_sort, 7);//�������������� ���������� ������ � ������

			Assert::AreEqual(ch_object_sort, sort);//��������, ��� ��������� ���������� ����� ���������� ����������
		}
	};
}