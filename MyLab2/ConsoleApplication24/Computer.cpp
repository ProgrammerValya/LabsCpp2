#include "stdafx.h"
#include "Computer.h"
#include "InputHelp.h"


Computer::Computer()
{
	//��� ����� ����������
	code = 0;
	//�������� ����� ����������
	string name = "";
	//��� ����������, 
	string CPUtype = "";
	//������� ������ ����������
	int frequency = 0;
	//����� ����������� ������ 
	int RAM = 0;
	//����� �������� ����� 
	int hardDrive = 0;
	//����� ������ ����������
	int videoCard = 0;
	//��������� ���������� 
	int cost = 0;
	//���������� �����������
	int count = 0;
}

Computer & Computer::operator=(Computer c)
{
	//��� ����� ����������
	code = c.code;
	//�������� ����� ����������
	name = c.name;
	//��� ����������, 
	CPUtype = c.CPUtype;
	//������� ������ ����������
	frequency = c.frequency;
	//����� ����������� ������ 
	RAM = c.RAM;
	//����� �������� ����� 
	hardDrive = c.hardDrive;
	//����� ������ ����������
	videoCard = c.videoCard;
	//��������� ���������� 
	cost = c.cost;
	//���������� �����������
	count = c.count;

	return (*this);
}

Computer Computer::InputScreenCompany()
{
	Computer c;
	c.code = InputNum(0, 1000000, "������� ��� ����� ����������: ");
	c.name = InputInfo("������� �������� ����� ����������: ");
	c.CPUtype = InputInfo("������� ��� ����������: ");
	c.frequency = InputNum(0, 3000, "������� ������� ������ ����������: ");
	c.RAM = InputNum(0, 4000, "������� ����� ����������� ������ : ");
	c.hardDrive = InputNum(0, 4000, "������� ����� �������� ����� : ");
	c.videoCard = InputNum(0, 4000, "������� ����� ������ ����������: ");
	c.cost = InputNum(0, 200000, "������� ��������� ���������� : ");
	c.count = InputNum(0, 100, "������� ���������� �����������: ");
	return c;
}

void Computer::OutputScreenComputer(Computer c)
{

	cout << "��� ����� ����������: " << c.code << endl;
	cout << "�������� ����� ����������: " << c.name << endl;
	cout << "��� ����������: " << c.CPUtype << endl;
	cout << "������� ������ ����������: " << c.frequency << endl;
	cout << "����� ����������� ������ : " << c.RAM << endl;
	cout << "����� �������� ����� : " << c.hardDrive << endl;
	cout << "����� ������ ����������: " << c.videoCard << endl;
	cout << "��������� ���������� : " << c.cost << endl;
	cout << "���������� �����������: " << c.count << endl;

}

string Computer::ToString(Computer c, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "��� ����� ����������: " + to_string(c.code) + "\n" + "�������� ����� ����������: " + c.name
		+ "\n" + "��� ����������: " + c.CPUtype + "\n" + "������� ������ ����������: " + to_string(c.frequency) + "\n" + "����� ����������� ������ : " +
		to_string(c.RAM) + "\n" + "����� �������� ����� : " + to_string(c.hardDrive) + "\n" + "����� ������ ����������: " + to_string(c.videoCard)
		+ "\n" + "��������� ���������� : " + to_string(c.cost) + "\n" + "���������� �����������: " + to_string(c.count) + "\n";
	return result;
}

string Computer::ReadString(ifstream input, string wrd, Computer c)
{
	string s;
	if (!input.eof())
	{///////////////////
		getline(input, s, '\n');
		
	}
	return(s.substr(wrd.length(), s.length()).c_str());

}

Computer Computer::ReadFromString(ifstream &input)  //??
{
	Computer c;
	string s;
	try
	{
		getline(input, s, '\n');
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����� ����������: ";
			c.code = atoi(s.substr(wrd.length(), s.length()).c_str());
		}

		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "�������� ����� ����������: ";
			c.name = s.substr(wrd.length(), s.length());
		}
	
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������: ";
			c.CPUtype = s.substr(wrd.length(), s.length());
		}

		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ������ ����������: ";
			c.frequency = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������� ������: ";
			c.RAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������� �����:  ";
			c.hardDrive = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ������ ����������: ";
			c.videoCard = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��������� ����������:  ";
			c.cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� �����������: ";
			c.count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ �� �����!" << endl;
	}
	return c;
}

Computer Computer::InputConditionType(int ConditionType, bool(**compare)(Computer, Computer), bool(**sort)(Computer, Computer))  //??
{
	Computer result;
	switch (ConditionType)
	{
	case 1:
		result.CPUtype = InputInfo("������� ������� ��� ����������: ");
		*compare = SearchCPU;
		*sort = SortCPU;
		return result;
	case 2:
		result.RAM = InputNum(0, 4000, "������� ������� ����� ���: ");
		*compare = SearchRAM;
		*sort = SortRAM;
		return result;
	case 3:
		result.videoCard = InputNum(0, 4000, "������� ������� ����� ����������: ");
		*compare = SearchVideoCard;
		*sort = SortVideoCard;
		return result;
	case 4:
		result.hardDrive = InputNum(0, 4000, "������� ����� ������� �������� �����: ");
		*compare = SearchhardDrive;
		*sort = SorthardDrive;
		return result;
	default:
		return result;
	}
}

bool Computer::SearchCPU(Computer n, Computer m)
{
	return n.CPUtype == m.CPUtype;
}

bool Computer::SearchRAM(Computer n, Computer m)
{
	return n.RAM == m.RAM;
}

bool Computer::SearchVideoCard(Computer n, Computer m)
{
	return n.videoCard == m.videoCard;
}

bool Computer::SearchhardDrive(Computer n, Computer m)
{
	return n.hardDrive == m.hardDrive;
}

bool Computer::SortCPU(Computer n, Computer m)
{
	return n.CPUtype > m.CPUtype;
}

bool Computer::SortRAM(Computer n, Computer m)
{
	return n.RAM > m.RAM;
}

bool Computer::SortVideoCard(Computer n, Computer m)
{
	return n.videoCard > m.videoCard;
}

bool Computer::SorthardDrive(Computer n, Computer m)
{
	return n.hardDrive > m.hardDrive;
}
