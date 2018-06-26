#include "stdafx.h"

#include "BuyingComputer.h"
#include "MyDate.h"
#include "InputHelp.h"
#include "User.h"


// �����������
BuyingComputer::BuyingComputer()
{
	code = 0;
	name = "";
	date = "";
}

// ������� ����� ��������� "��������� ���������" � �������. �� ���� ����� ��������� ��� � ��� ������. 
BuyingComputer::BuyingComputer(string _name, int _code)
{
	//BuyingComputer c;
	MyDate mydate;
	code = _code;
	name = _name;
	mydate.InputDate();
	date = mydate.ToString();
	//return c;
}

// ������� ������ ��������� "��������� ���������" �� �������
void BuyingComputer::OutputScreenBuyingComputer(BuyingComputer c)
{
	cout << setw(10) << setiosflags(ios::left) << c.code << "|";																	
	cout << setw(15) << setiosflags(ios::left) << c.name << "|";
		cout << setw(15) << setiosflags(ios::left) << c.date << "|" << endl;;
}

// ����� ���������
void BuyingComputer::OutputScreenHeaderBuyingComputer()
{
	cout << setw(4) << setiosflags(ios::left) << "�" << "|";
	cout << setw(10) << setiosflags(ios::left) << "��� �����" << "|";
	cout << setw(15) << setiosflags(ios::left) << "����������" << "|";
	cout << setw(15) << setiosflags(ios::left) << "����" << "|" << endl;
	cout << "------------------------------------------------------------" << endl;
}

// ������ � �������� ����
void BuyingComputer::WriteBuyingComputerToFile(BuyingComputer a, ofstream& os)
{
	//(char*)&i-������ ������ ������, ����� ������, ��������� ������ � �������� ������
	//sizeof(int)-������������ ����� �������� � ����� ������ 
	os.write((char*)&a.code, sizeof(int));  //���������� ��� ����������
	StringInBinFile(os, a.name);  //���������� �����
	StringInBinFile(os, a.date);  //���������� ����
	
}

// ���������� �� ��������� �����
BuyingComputer BuyingComputer::ReadBuyingComputerFromFile(ifstream& in)
{
	BuyingComputer a;

	in.read((char*)&a.code, sizeof(int)); //��������� ���
	a.name = StringFromBinFile(in);  //��������� �����
	a.date = StringFromBinFile(in);  //��������� ����

	return a;
}







