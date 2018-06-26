// ConsoleApplication24.cpp: ���������� ����� ����� ��� ����������� ����������.
/*�������� ���������� :
C) ������(std::list)
������� �������������� :
9. �������� ������ ������ ����� �� ������ ������������� �����.*/


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <list>  
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cstring>
#include <clocale> 
#include <string.h>
#include <stdio.h> 
#include <string>

using namespace std;

//��������������� ������� ��� ���������� ���������� ����� N ������ ���������� ������� � �����.
int Random(int M)
{
	return rand() % (2 * M + 1) - M;
}

// ������� ���������� ���������� ����� N ������ ���������� ������� � ��������� �� - M �� M, � �����.
ofstream FillFileRandom(string FileName,int N, int M)  
{
	ofstream input(FileName);
	list<int> l1;
	srand(time(0)); 
	for (int i = 0; i < N; i++)
		l1.push_back(Random(M));
	copy(l1.begin(), l1.end(), ostream_iterator<int>(input, " "));  //����� � ����
	input.close();
	return input;
}

class RandomRange
{
private:
	int M;  //��������
public:
	RandomRange(const int& x) : M(x)
	{}
	int operator ( ) () const  
	{
		return rand() % (2 * M + 1) - M;
	}
};

// ������� ���������� ���������� ����� N ������ ���������� ������� � ��������� �� - M �� M, � �������������� generate.
ofstream FillFileGenerate(string FileName, int N, int M)  
{
	ofstream input(FileName);
	list<int> l1(N);
	srand(time(0));  
	generate(l1.begin(), l1.end(), RandomRange(M));   
	copy(l1.begin(), l1.end(), ostream_iterator<int>(input, " "));  //����� � ����
	input.close();
	return input;
}

//�������, ���������� ���� �� ����, � ������������ ���������������� ���������, ����������� ������� �� �����.
list<int> LoadFromFile(string FileName)//������ �� ������� �������� �� ���� ��� �����!!!??
{
	
	ifstream  input(FileName);
	list<int> OutputList;
	int buff; // ����� �������������� �������� ������������ �� ����� ������
	input.seekg(0);
	while (!input.eof())	//��������� ��������� ������� �� �����
	{
		input >> buff;
		OutputList.push_back(buff); 		
	}
	input.close();
	return OutputList;
}

//�������, ����������� �����, ������������ � ����������.
int Sum(list<int> l1)
{
	return accumulate(l1.begin(), l1.end(), 0); //�� ��������� accumulate ��������� ��������, 0-����� ������. 
}

//�������, ����������� ������� �������������� �����, ������������ � ����������.
double SrArifm(list<int> l1)
{
	if (l1.empty())
	{
		throw "������ ����!";
	}
	

	return (Sum(l1) / l1.size()); //�����
}

// ����� ������� �������������� �����
int SearchFirstNeg(list<int>::iterator begin, list<int>::iterator end)
{
	int FirstNeg = *begin;
	bool find = false;
	std::list<int>::iterator it = begin;
	
		while ((it != end) && !find)
		{
			if ((*it) < 0)
			{
				find = true;
				FirstNeg = *it;
			}
			it++;
	
		if (find) return FirstNeg;
		else throw "��� ������������� �����";
	}
	
}

//������������� ������� modify, ����������� �� ���� ��������� ������ � ����� �������������� ����� ����������.
list<int> modify(list<int>::iterator begin, list<int>::iterator end)
{
	list<int> OutputList;
	int FirstNeg = SearchFirstNeg(begin, end);  
	for (auto it = begin; it != end; it++)
	{
		if ((*it) % 2 == 0)
		{
			(*it) = (*it)*FirstNeg;
		}
		OutputList.push_back(*it);
	}
	return OutputList;
}

// ������������� ������� modify, ����������� �������������� ����������� ����������.
list<int> modify(list<int> l1)
{
	return modify(l1.begin(), l1.end());
}

class xform		
{
private:
	int n;  //�����, �� ������� ����� �������� ������� �.�. ������ ������������� �����
public:
	xform(const int& x) : n(x) 
	{
	}

	int operator ( ) (int& elem) const  //�������� �������� ������� �� n �.�. �� ����������� � ����������� �����
	{
		if (elem % 2==0)
			elem = n*elem;
		return elem;
	}
};

//�������, ����������� ��������� �������������� � �������������� ��������� std::transform ������ ������� modify.
list<int> ModifyTransform(list<int> l1)
{
	int FirstNeg = SearchFirstNeg(l1.begin(), l1.end());
	std::transform(l1.begin(), l1.end(),l1.begin(),xform(FirstNeg));
	return l1;
}

//�������, ����������� ��������� �������������� � �������������� ��������� std::for_each ������ ������� modify.
list<int> ModifyForEach(list<int> l1)
{
	int FirstNeg;
	SearchFirstNeg(l1.begin(), l1.end());
	for_each(l1.begin(), l1.end(), xform(FirstNeg));
	return l1;
}

// �������� ������������ ������� � ����� ����� 
bool CorrectSb(char c)
{
	switch (c)
	{
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
		return false;
	default:
		return true;
	}
}

// �������� �������� ������������ �����	
bool CorrectName(string name)
{
	int i = 1;
	bool OkName = true;
	for (i=1;((i<name.length()) && OkName);i++)
		OkName = CorrectSb(name[i]);
	return OkName;
}

//���� ����� �����	
string InputFileName()
{
	char* FileName;
	FileName = new char[45];
	 while (true)
	 {
		 cout << "������� ��� �����:  ";
		 cin >> FileName;
		 if (CorrectName(FileName))
		 {
			 strcat(FileName, ".txt");  	 
			 break;
		 }
		 else
			 cout << "� ����� ����� ������\n";
	 }
	return FileName;
}

// ������ ������ �� �����
void Print(list<int> l1)
{
	copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
}

// ������ ������ � ����
void PrintToFile(string FileName,list<int> &InputList)
{
	ofstream File;
	File.open(FileName, ios::out);
	if (File)
	{
		list<int>::const_iterator it;
		copy(InputList.begin(), InputList.end(), ostream_iterator<int>(File, " "));
		cout << endl << "���� �������!" << endl;
		File.close();
	}
	else
	{
		cout << "������ �������� �����!" << endl;
	}
}

//��� ����
int InputNumber(int min, int max)
{
	int n=-1;
	while ((n < min) || (n > max))
	{
		cout << "������� �����: ";
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cout << "������������ �����\n";
			cin.clear();
			cin.sync();
			cout << "������� �����: ";
		}
	};
	return n;
}

//��� ����� N � M
int InputData(const string text)
{
	int n = -1;
	cout<<text;
	cin >> n;
	while (n < 0)
	{
		cout << "������������ �����\n";
		cout << "������� �����: ";
		cin >> n;
	};	
	return n;
} 

int Menu()
{
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - ��������� �����" << endl;
	cout << "2 - ��������� ������� ��������������" << endl;
	cout << "3 - Modify(�������������� ������ )" << endl;
	cout << "4 - Modify(�������������� ������ - ������������� �������) " << endl;
	cout << "5 - �������������� � ������� transform" << endl;
	cout << "6 - �������������� � ������� for_each" << endl;
	cout << "7 - ����� �� ����� " << endl;
	cout << "8 - ����� � ����" << endl;
	cout << "0 - ����� " << endl;
	int n = InputNumber(0, 8);
	cout << "\n";
	return n;
}


int main()
{	
	setlocale(LC_ALL, "Russian");
	int item; 
	bool enterfile = true;
	ofstream OutputFile;
	string FileName="";
	int N = 5;//���-�� ����� � �������
	int M; //��������
	list<int> MyList;	
	cout << "1 - ���������� ����� ����� generate" << endl;
	cout << "2 - ���������� ����� ����� ����" << endl;
	cout << "0 - �����" << endl;
	item = InputNumber(0, 2);
	switch (item)
	{
	case 1:
	{
		FileName = InputFileName();
		N = InputData("������� N,���������� ��-���: ");
		M = InputData("������� M, �������� ��������: ");
		OutputFile = FillFileGenerate(FileName, N, M);
		break;		
	}
	case 2:
	{
		FileName = InputFileName();
		N = InputData("������� N,���������� ��-���: ");
		M = InputData("������� M, �������� ��������: ");
		OutputFile = FillFileRandom(FileName, N, M);
		break;	
	}
	default:
		enterfile = false;
		exit(0);
		break;
	}

	if (enterfile)
	{		
		MyList = LoadFromFile(FileName);
		for (;;)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				cout << "�����: " << Sum(MyList) << endl;
				break;
			case 2:
				cout << "������� ��������������: " << SrArifm(MyList) << endl;
				break;
			case 3:
				try
				{
					MyList = modify(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;				
			case 4:
				try
				{
					MyList = modify(MyList.begin(), MyList.end());
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 5:
				try
				{
					MyList = ModifyTransform(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 6:
				try
				{
					MyList = ModifyForEach(MyList);
				}
				catch (const string text)
				{
					cout << text << endl;
				}
				break;
			case 7:
				cout << "������: " << endl;
				Print(MyList);
				break;
			case 8:
				PrintToFile(FileName,MyList);
				break;
			default:
				cout << "����� " << endl; exit(0);
				break;
			}
		}
	}
	else
		cout << "�����\n";
	system("pause");

}

