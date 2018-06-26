#include "stdafx.h"
#include "InputHelp.h"

string InputInfo(string info)
{
	string a;
	cout << info;
	cin >> a;
	return a;
}

bool CorrectSymbol(char c)
{
	switch (c)
	{

	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}

bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

string InputFileName()
{

	string filename;
	do
	{
		cout << "������� ��� �����:  ";
		cin >> filename;

		if (CorrectName(filename))
		{

			break;
		}
		else
			cout << "�������� ��� �����\n";
	} while (true);

	return filename;
}

string StringFromBinFile(ifstream & in)
{
	string result;
	__int64 len_name; ww
	in.read((char*)&len_name, sizeof(len_name)); // ������ ����� ���������� ������
	char * buf = new char[len_name];         // ��������� ������ ��� ������
	in.read(buf, len_name);// ������ (� ������� ������)
	result = buf;                       // ���������� ��������� ������ 
	delete[]buf;               // ������������ ������

	return result;
}

void StringInBinFile(ofstream & os, string str)
{

	__int64 len_name = str.length() + 1;  // ����� � ������� ������
	os.write((char*)&len_name, sizeof(__int64)); // ������ �����
	os.write(str.c_str(), len_name);  // ������ ����������
}

int InputNumInt(int min, int max, string message)
{
	int n;
	bool flag = true;
	do
	{
		if (!flag)
			cout << "����� ��� ���������!!\n";
		else
			flag = !flag;
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "������������ ���� !!  ��������� ����!\n";
			cin.clear();  // ��������������� ����� ���� �� � ��������� ���������
			cin.sync();   // ������� ����� �� ��������� ��������
			cout << message;
			getchar();
			getchar();
		}
		/*cout << "������������ ���� !!  ��������� ����!\n";*/
	} while ((n < min) || (n > max));
	return n;
}
