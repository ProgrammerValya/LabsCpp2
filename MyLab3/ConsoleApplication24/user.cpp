#include "stdafx.h"

#include "User.h"
#include "InputHelp.h"
#include "BuyingComputer.h"
#include "Computer.h"


// ����� "User"
// �����������. �� ���� ��������� ��� ����� ������� ����������, ��� ����� ������� �������
User::User(string _filename_model_PC, string _filename_history_buy)
{
	filename_model_PC = _filename_model_PC;
	filename_history_buy = _filename_history_buy;
	// ���������� ���������� �� ������ � ������ � �������� ����������� � � ������ � ��������� �������
	vectModelComputer.ReadFromFile(Computer::ReadComputerFromFile, filename_model_PC);
	vectBuyingComputer.ReadFromFile(BuyingComputer::ReadBuyingComputerFromFile, filename_history_buy);
}

//����� ������ ������� �� � ����������� ���������� ����  
vector<Computer> User::LookModelPCToCriteria()
{
	Computer c;

	bool(*compare)(Computer, Computer) = NULL;
	bool(*sort)(Computer, Computer) = NULL;

	vector<Computer> subset;

	int numb = InputNumInt(1, 9, "�������� ��� ������:\n 1 - �� ���� ����� ����������\n 2 - �� �������� ����� ����������\n 3 - �� ���� ����������\n 4 - �� ������� ������ ���������� \n 5 - �� ������ ����������� ������ \n 6 - �� ������ �������� ����� \n 7 - ������ ������ ���������� \n 8 - �� ��������� ���������� \n 9 - �� ���������� �����������\n---> ");
	c = c.InputConditionType(numb);
	switch (numb)
	{
	case 1:

		compare = c.SearchCode;
		sort = c.SortCode;
		break;
	case 2:

		compare = c.SearchNameComputer;
		sort = c.SortNameComputer;
		break;
	case 3:

		compare = c.SearchCPU;
		sort = c.SortCPU;
		break;
	case 4:

		compare = c.SearchFrequency;
		sort = c.SortFrequency;
		break;
	case 5:

		compare = c.SearchRAM;
		sort = c.SearchRAM;
		break;
	case 6:

		compare = c.SearchhardDrive;
		sort = c.SorthardDrive;
		break;

	case 7:

		compare = c.SearchVideoCard;
		sort = c.SortVideoCard;
		break;

	case 8:

		compare = c.SearchCost;
		sort = c.SortCost;
		break;
	case 9:

		compare = c.SearchCount;
		sort = c.SortCount;
		break;
	}
	subset = vectModelComputer.BinarySearch(c, sort, compare);
	if (subset.size() != 0)
		//������� ��� ����� ������������ � ����������� �� ������� ����
		vectModelComputer.OutputScreen(subset, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
	else
		cout << "�������� �� �������" << endl;
	return subset;
}

// ���������� ������ PC
void User::ReadModelPC()
{
	vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
}


// �����
void User::Close()
{
	vectModelComputer.OutputFile(Computer::WriteComputerToFile, filename_model_PC);
	vectBuyingComputer.OutputFile(BuyingComputer::WriteBuyingComputerToFile, filename_history_buy);
}

