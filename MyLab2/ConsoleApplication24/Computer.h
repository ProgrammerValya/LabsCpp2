#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
//
#include <string>


using namespace std;
class Computer
{  //!!
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
	
	// ������������� �������� ��������� ��� ��������� "���������"
	Computer& operator = (Computer c);
	
// ������� ����� ��������� "���������" � �������
	static Computer InputScreenCompany();

// ������� ������ ��������� "���������" �� �������
	static void OutputScreenComputer(Computer c);

//������� ��������� "���������" � ������
	static string ToString(Computer c, int /**/i);

static string ReadString(ifstream input, string wrd, Computer c);

//���������� ��������� "���������" �� ������
static Computer ReadFromString(ifstream& input);

// ���� �������� ������ � ����������� �� ���������� ���� 
//1 - �� ���� ����������
//2 - ��  ������ ���
//3 - �� ������ ����������
//4 - �� ������ �������� �����
static Computer InputConditionType(int ConditionType, bool(**compare)(Computer, Computer), bool(**sort)(Computer, Computer));

// ����� ������� �������� �� ���������� ��������
//�� ���� ����������
static bool SearchCPU(Computer n, Computer m);

//��  ������ ���
static bool SearchRAM(Computer n, Computer m);

//�� ������ ����������
static bool SearchVideoCard(Computer n, Computer m);

//�� ������ �������� �����
static bool SearchhardDrive(Computer n, Computer m);

// ��������� �������� � ����������� �� ���������� ���� ��� ����������
//�� ���� ����������
static bool SortCPU(Computer n, Computer m);

//��  ������ ���
static bool SortRAM(Computer n, Computer m);

//�� ������ ����������
static bool SortVideoCard(Computer n, Computer m);

// �� ������ �������� �����
static bool SorthardDrive(Computer n, Computer m);

};

