#include "stdafx.h"

#include "Client.h"

#include "InputHelp.h"
#include "BuyingComputer.h"
#include "Computer.h"
#include "User.h"

// ����� �������

// �����������
Client::Client(string _name_client, string _filename_model_PC, string _filename_history_buy) :User(_filename_model_PC, _filename_history_buy)
{
	name_client = _name_client;

}

// ����� � �������� ( ������� ���� ��� ���� ���-�� ����������� ������ ���������� ��� �������)
void Client::BuyingModelPC()   
{
	Computer c;

	bool(*compare)(Computer, Computer) = NULL;
	bool(*sort)(Computer, Computer) = NULL;
	//� ��������� ������� ��� ��������� �� ������� ������� ����������
	vector<Computer> subset;
	//�������� �� ������ �������� ������ ���������
	subset = LookModelPCToCriteria();
	
	if (subset.size() != 0)
	{
		//������� ��������� �� �����
		//vectModelComputer.OutputScreen(subset, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
		int num = InputNumInt(0, subset.size(), "�������� ����� ���������� ( 0 - ���� ���������� ��������): ");
		if (num != 0)
		{
			// ����� ������ ����������� ��-�� � ���������  
			int n = vectModelComputer.LinearySearchElem(subset[num - 1]);
			//���������� ���������� ����������� ������ ������
			int count_ekz = vectModelComputer.vect[n].get_Count();
			// ���� ���-�� ����������� ������ 0 (��� ���� � �������)
			if (count_ekz > 0)
			{
				// ������ "��������� ���������"  � ������� (����� �������� ��� ������� � ��� �����)  //������ ������� ������� � ����������
				BuyingComputer buyComputer = BuyingComputer::BuyingComputer(name_client, vectModelComputer.vect[num - 1].get_Code());
				// ���������� � ������ ������� (� ������� �������)
				vectBuyingComputer.Add(buyComputer); //���������
													 // ���������� ���-�� ����������� �� 1
				vectModelComputer.vect[num - 1].set_Count(count_ekz - 1);
			}
			else
				cout << "��� ����������� � �������!!" << endl;
		}
		else
			cout << "������� ��������!" << endl;
	}
	else
		cout << "�������� �� �������" << endl;
}



// ����
void Client::Menu()
{

	int changemenu = 0;
	while (changemenu != 4)
	{
		cout << " --------------------���� �������---------------------  " << endl;
		cout << "1 - ����� ������ ��" << endl;
		cout << "2 - ������� ������ ��" << endl;
		cout << "3 - ���������� ��� ������ ��" << endl;
		cout << "4 - �����" << endl;

		changemenu = InputNumInt(1, 4, "---> ");
		switch (changemenu)
		{
		case 1:
			LookModelPCToCriteria();
			break;

		case 2:
			BuyingModelPC();
			break;
		case 3:
			ReadModelPC();
			break;

		case 4:
			Close();
			break;

		default:
			exit(1);
			break;
		}
	}
}


