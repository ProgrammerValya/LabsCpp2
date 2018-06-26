#pragma once
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Computer
{
private:
	//��� ����� ����������
	int code;
	//�������� ����� ����������
	string name;
	//��� ����������, 
	string CPUtype;
	//������� ������ ����������
	int frequency;
	//����� ����������� ������ 
	int RAM;
	//����� �������� ����� 
	int hardDrive;
	//����� ������ ����������
	int videoCard;
	//��������� ���������� 
	int cost;
	//���������� �����������
	int count;

public: /// ��������� ����
		// ����������� �� ���������
	Computer();

	// �������� ��� ����
	int get_Code();

	// �������� ��� ���-��
	int get_Count();

	// �������� ��� ���-��
	void set_Count(int value);

	// ������� ����� ��������� "���������" � �������
	static Computer InputScreenComputer();

	// ������� ������ ��������� "���������" �� �������
	static void OutputScreenComputer(Computer c);

	// ����� ���������
	static void OutputScreenHeaderComputer();

	// ���� �������� ������ � ����������� �� ���������� ���� 
	static Computer InputConditionType(int ConditionType);

	// ������ � �������� ����
	static void WriteComputerToFile(Computer a, ofstream& os);

	// ���������� �� ��������� �����
	static Computer ReadComputerFromFile(ifstream& in);

	// ��������� ����������
	static Computer ChangeComputer(Computer &comp);

	// ����� ������� �������� �� ���������� ��������
	//�� ���� ����������
	//�� ����
	static bool SearchCode(Computer n, Computer m);

	static bool SearchCPU(Computer n, Computer m);

	//��  ������ ���
	static bool SearchRAM(Computer n, Computer m);

	//�� ������ ����������
	static bool SearchVideoCard(Computer n, Computer m);

	//�� ������ �������� �����
	static bool SearchhardDrive(Computer n, Computer m);

	// �� ����� �����
	static bool SearchNameComputer(Computer n, Computer m);

	//������� ������ ����������
	static bool SearchFrequency(Computer n, Computer m);

	//��������� ���������� 
	static bool SearchCost(Computer n, Computer m);

	//���������� �����������
	static bool SearchCount(Computer n, Computer m);

	//-------��������� ��������
	// �� ����� 
	static bool SortCode(Computer n, Computer m);

	// �� ����� �����
	static bool SortNameComputer(Computer n, Computer m);

	// �� �������
	static bool SortFrequency(Computer n, Computer m);

	// �� ����
	static bool SortCost(Computer n, Computer m);

	// �� ���-��
	static bool SortCount(Computer n, Computer m);

	//�� ���� ����������
	static bool SortCPU(Computer n, Computer m);

	//��  ������ ���
	static bool SortRAM(Computer n, Computer m);

	//�� ������ ����������
	static bool SortVideoCard(Computer n, Computer m);

	// �� ������ �������� �����
	static bool SorthardDrive(Computer n, Computer m);

	// �������������� �������� ���������
	friend bool operator ==(const Computer &a, const Computer &b);//���������� ==

};

