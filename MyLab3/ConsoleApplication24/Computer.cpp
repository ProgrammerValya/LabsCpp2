#include "stdafx.h"
#include "Computer.h"
#include "InputHelp.h"
// ����������� �� ���������
Computer::Computer()
{
	//��� ����� ����������
	code = 0;
	//�������� ����� ����������
	name = "";
	//��� ����������, 
	CPUtype = "";
	//������� ������ ����������
	frequency = 0;
	//����� ����������� ������ 
	RAM = 0;
	//����� �������� ����� 
	hardDrive = 0;
	//����� ������ ����������
	videoCard = 0;
	//��������� ���������� 
	cost = 0;
	//���������� �����������
	count = 0;
}

// �������� ��� ����
int Computer::get_Code()
{
	return code;
}

// �������� ��� ���-��
int Computer::get_Count()
{
	return count;
}

// �������� ��� ���-��
void Computer::set_Count(int value)
{
	count = value;
}


// ������� ����� ��������� "���������" � �������
Computer Computer::InputScreenComputer()
{
	Computer c;
	c.code = InputNumInt(0, 1000000, "������� ��� ����� ���������� (0 - 1000000): ");
	c.name = InputInfo("������� �������� ����� ����������: ");
	c.CPUtype = InputInfo("������� ��� ����������: ");
	c.frequency = InputNumInt(0, 3000, "������� ������� ������ ���������� (0 - 3000): ");
	c.RAM = InputNumInt(0, 4000, "������� ����� ����������� ������ (0 - 4000): ");
	c.hardDrive = InputNumInt(0, 4000, "������� ����� �������� ����� (0 - 4000): ");
	c.videoCard = InputNumInt(0, 4000, "������� ����� ������ ���������� (0 - 4000): ");
	c.cost = InputNumInt(0, 500000, "������� ��������� ���������� (0 - 500000): ");
	c.count = InputNumInt(0, 100, "������� ���������� ����������� (0 - 100): ");
	return c;
}

// ������� ������ ��������� "���������" �� �������
void Computer::OutputScreenComputer(Computer c)
{
	cout << setw(9) << setiosflags(ios::left) << c.code << "|";
	cout << setw(7) << setiosflags(ios::left) << c.name << "|";
	cout << setw(15) << setiosflags(ios::left) << c.CPUtype << "|";
	cout << setw(5) << setiosflags(ios::left) << c.frequency << "|";
	cout << setw(5) << setiosflags(ios::left) << c.RAM << "|";
	cout << setw(5) << setiosflags(ios::left) << c.hardDrive << "|";
	cout << setw(5) << setiosflags(ios::left) << c.videoCard << "|";
	cout << setw(5) << setiosflags(ios::left) << c.cost << "|";
	cout << setw(3) << setiosflags(ios::left) << c.count << endl;

}

void Computer::OutputScreenHeaderComputer()
{
	//setw-������ �������� ������ ��� ������� ��������,   setiosflags-����� � ������������� �����
	cout << setw(4) << setiosflags(ios::left) << "�" << "|";
	cout << setw(7) << setiosflags(ios::left) << "��� �����" << "|";
	cout << setw(7) << setiosflags(ios::left) << "�����" << "|";
	cout << setw(7) << setiosflags(ios::left) << "��� ���������� " << "|";
	cout << setw(5) << setiosflags(ios::left) << "��" << "|";
	cout << setw(5) << setiosflags(ios::left) << "RAM" << "|";
	cout << setw(5) << setiosflags(ios::left) << "HDD" << "|";
	cout << setw(5) << setiosflags(ios::left) << "GPU" << "|";
	cout << setw(5) << setiosflags(ios::left) << "����" << "|";
	cout << setw(3) << setiosflags(ios::left) << "���-��" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

// ������ � �������� ����
void Computer::WriteComputerToFile(Computer a, ofstream& os)
{
	os.write((char*)&a.code, sizeof(int));
	StringInBinFile(os, a.name);
	StringInBinFile(os, a.CPUtype);
	os.write((char*)&a.frequency, sizeof(int));
	os.write((char*)&a.RAM, sizeof(int));
	os.write((char*)&a.hardDrive, sizeof(int));
	os.write((char*)&a.videoCard, sizeof(int));
	os.write((char*)&a.cost, sizeof(int));
	os.write((char*)&a.count, sizeof(int));

}

// ���������� �� ��������� �����
Computer Computer::ReadComputerFromFile(ifstream& in)
{
	Computer a;

	in.read((char*)&a.code, sizeof(int));
	a.name = StringFromBinFile(in);
	a.CPUtype = StringFromBinFile(in);
	in.read((char*)&a.frequency, sizeof(int));
	in.read((char*)&a.RAM, sizeof(int));
	in.read((char*)&a.hardDrive, sizeof(int));
	in.read((char*)&a.videoCard, sizeof(int));
	in.read((char*)&a.cost, sizeof(int));
	in.read((char*)&a.count, sizeof(int));

	return a;
}

// ��������� ����������
Computer Computer::ChangeComputer(Computer &comp)
{
	if (InputNumInt(0, 1, "�� ������ �������� ��� ����� ����������  " + to_string(comp.code) + " (0 - ���, 1 - ��)\n-->: ") == 1)
		comp.code = InputNumInt(0, 10000, "������� ����� ��� �����: ");
	if (InputNumInt(0, 1, "�� ������ �������� �������� ����� ���������� " + comp.name + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		comp.name = InputInfo("������� ����� �������� ����� ����������: ");
	if (InputNumInt(0, 1, "�� ������ �������� ��� ���������� " + comp.CPUtype + " (0 - ���, 1 - ��)\n��� �����: ") == 1)
		comp.CPUtype = InputInfo("������� ����� ��� ����������: ");
	if (InputNumInt(0, 1, "�� ������ �������� ������� ������ ������c��� " + to_string(comp.frequency) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.frequency = InputNumInt(0.0, 1000.0, "������� ����� ������� ������ ������c��� (0 - 1000000): ");
	if (InputNumInt(0, 1, "�� ������ �������� ����� ����������� ������  " + to_string(comp.RAM) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.RAM = InputNumInt(0, 1000, "������� ����� ����� ����������� ������ (0 - 1000): ");
	if (InputNumInt(0, 1, "�� ������ �������� ����� �������� �����  " + to_string(comp.hardDrive) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.hardDrive = InputNumInt(0, 1000, "������� ����� ����� �������� �����  (0 - 1000): ");
	if (InputNumInt(0, 1, "�� ������ �������� ����� ������ ���������� " + to_string(comp.videoCard) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.videoCard = InputNumInt(0, 1000, "������� ����� ����� ������ ���������� (0 - 1000): ");
	if (InputNumInt(0, 1, "�� ������ �������� ��������� ����������  " + to_string(comp.cost) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.frequency = InputNumInt(0.0, 1000000.0, "������� ����� ��������� ���������� (0 - 1000000): ");
	if (InputNumInt(0, 1, "�� ������ �������� ���������� �����������  " + to_string(comp.count) + " (0-���, 1 - ��)\n��� �����: ") == 1)
		comp.frequency = InputNumInt(0, 4000, "������� ����� ���������� ����������� (0 - 4000): ");

	return comp;
}



// ���� �������� ������ � ����������� �� ���������� ���� 
//1 - �� ���� ����������
//2 - ��  ������ ���
//3 - �� ������ ����������
//4 - �� ������ �������� �����
Computer Computer::InputConditionType(int ConditionType)
{
	Computer result;
	switch (ConditionType)
	{
	case 1:
		result.code = InputNumInt(0, 10000, "������� ������� ��� ����� ����������: ");
		return result;
	case 2:
		result.name = InputInfo("������� ������� �������� �����: ");
		return result;
	case 3:
		result.CPUtype = InputInfo("������� ������� ��� ����������: ");
		return result;
	case 4:
		result.frequency = InputNumInt(0.0, 10000, "������� ������� �������: ");
		return result;
	case 5:
		result.RAM = InputNumInt(1, 1000, "������� ������� ����� ���: ");
		return result;
	case 6:
		result.hardDrive = InputNumInt(1, 1000, "������� ������� ����� �������� �����: ");
		return result;
	case 7:
		result.videoCard = InputNumInt(0, 1000, "������� ������� ����� ������ ����������: ");
		return result;
	case 8:
		result.cost = InputNumInt(0, 500000, "������� ������� ����: ");
		return result;
	case 9:
		result.count = InputNumInt(0, 4000, "������� ������� ���-��: ");
		return result;
	default:
		return result;
	}
}

// ����� ������� �������� �� ���������� ��������
//�� ���� ����������
bool Computer::SearchCPU(Computer n, Computer m)
{
	return n.CPUtype == m.CPUtype;
}
//��  ������ ���
bool Computer::SearchRAM(Computer n, Computer m)
{
	return n.RAM == m.RAM;
}
//�� ������ ����������
bool Computer::SearchVideoCard(Computer n, Computer m)
{
	return n.videoCard == m.videoCard;
}
//�� ������ �������� �����
bool Computer::SearchhardDrive(Computer n, Computer m)
{
	return n.hardDrive == m.hardDrive;
}

// �� ���� �����
bool Computer::SearchCode(Computer n, Computer m)
{
	return n.code == m.code;
}

// �� �������� �����
bool Computer::SearchNameComputer(Computer n, Computer m)
{
	return n.name == m.name;
}

bool Computer::SearchFrequency(Computer n, Computer m)
{

	return n.frequency == m.frequency;
}

//��������� ���������� 
bool Computer::SearchCost(Computer n, Computer m)
{

	return n.cost == m.cost;
}

//���������� �����������
bool Computer::SearchCount(Computer n, Computer m)
{
	return n.count == m.count;
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
//�� ���� ����������
bool Computer::SortCPU(Computer n, Computer m)
{
	return n.CPUtype > m.CPUtype;
}
//��  ������ ���
bool Computer::SortRAM(Computer n, Computer m)
{
	return n.RAM > m.RAM;
}
//�� ������ ����������
bool Computer::SortVideoCard(Computer n, Computer m)
{
	return n.videoCard > m.videoCard;
}
// �� ������ �������� �����
bool Computer::SorthardDrive(Computer n, Computer m)
{
	return n.hardDrive > m.hardDrive;
}

bool Computer::SortCode(Computer n, Computer m)
{
	return n.code > m.code;
}

// �� ����� �����
bool Computer::SortNameComputer(Computer n, Computer m)
{
	return n.name > m.name;
}

// �� ������� !!
bool Computer::SortFrequency(Computer n, Computer m)
{
	return (n.frequency  > m.frequency);
}

// �� ���� !!
bool Computer::SortCost(Computer n, Computer m)
{
	return n.cost > m.cost;
}

// �� ���-�� 
bool Computer::SortCount(Computer n, Computer m)
{

	return n.count > m.count;
}


// �������������� �������� ���������
bool operator ==(const Computer &a, const Computer &b)//���������� ==
{
	
	//return ((a.code == b.code) && (a.name == b.name) && (a.CPUtype == b.CPUtype) && (abs(a.cost - b.cost) < e) && (a.count == b.count) && (abs(a.frequency - b.frequency) < e) && (a.hardDrive == b.hardDrive) && (a.RAM == b.RAM) && (a.videoCard == b.videoCard));
	return ((a.code == b.code) && (a.name == b.name) && (a.CPUtype == b.CPUtype) && (a.cost == b.cost) && (a.count == b.count) && (a.frequency == b.frequency) && (a.hardDrive == b.hardDrive) && (a.RAM == b.RAM) && (a.videoCard == b.videoCard));
}

