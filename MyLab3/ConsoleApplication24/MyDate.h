#pragma once
#include <string>
#include <sstream>
using namespace std;

class MyDate
{
	// �������� �������� �� ��� ����������
	bool IsLeap(int year);
	// �������� ���� �� ������������
	bool CorrectDate(int day, int month, int year, string &message);
	// ����
	int day;
	// �����
	int month;
	// ���
	int year;

public:

	// ����������� �� ���������
	MyDate();

	// ���� ���� � �������
	void InputDate();

	// ������� ���� � ������ (��� ����������� ������ � ����)
	string ToString();

	// ������������� �������� ���������
	bool operator == (const MyDate &c);

	// ����������� �����������
	MyDate& operator = (MyDate c);

	// ������������� �������� ������
	bool operator > (const MyDate &c);

	// ������������� �������� ������
	bool operator < (const MyDate &c);

	//���������� ��������� "����" �� ������ 
	// ������:
	// ���� ����� ���
	static MyDate FromString(string str);
};



