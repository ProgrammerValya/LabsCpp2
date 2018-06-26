#include "stdafx.h"

#include "worker.h"

#include "BuyingComputer.h"
#include "InputHelp.h"
#include "Computer.h"


Worker::Worker(string _filename_model_PC, string _filename_history_buy) :User(_filename_model_PC, _filename_history_buy)
{

}


// �������� ������ PC. ������ ����������� � ������ ����������� � Uses
void Worker::AddModelPC()
{
	vectModelComputer.Add(Computer::InputScreenComputer());
}

// �������� ������ PC
void Worker::ChangeModelPC()
{
	if (vectModelComputer.Is_empty())
		cout << "��� ����� �����";
	else
	{
		vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
		int numb = InputNumInt(0, vectModelComputer.size(), "\n������� ����� ���������� ������ (0 - ���� ���������� ��������): ");
		if (numb != 0)
		{
			Computer::ChangeComputer(vectModelComputer.vect[numb - 1]);
			/*vectModelComputer.OutputFile(Computer::WriteComputerToFile, filename_model_PC);*/ // ����� �������������� ����� ������� ��������� ����� ����� ��� ������
			cout << "������ ��������!" << endl;                                            // ����� ������� �� x �� ��������������
		}
	}
}

// ������� ������ PC
void Worker::DeleteModelPC()
{
	vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
	vectModelComputer.Remove(InputNumInt(0, vectModelComputer.size(), "������� ����� ���������� �������� ( 0 - ���� ���������� �������): "));
}

// ���������� ������� �������
void Worker::ReadHistoryBuying()
{
	vectBuyingComputer.OutputScreen(vectBuyingComputer.vect, BuyingComputer::OutputScreenBuyingComputer, BuyingComputer::OutputScreenHeaderBuyingComputer);
}

// ����
void Worker::Menu()
{

	int changemenu = 0;
	while (changemenu != 6)
	{

		cout << " --------------------���� ����������---------------------  " << endl;
		cout << "1 - �������� ������ ��" << endl;
		cout << "2 - �������� ������ ��" << endl;
		cout << "3 - ������� ������ ��" << endl;
		cout << "4 - ���������� ������ ��" << endl;
		cout << "5 - ���������� ������� �������" << endl;
		cout << "6 - �����" << endl;
		changemenu = InputNumInt(1, 6, "---> ");
		switch (changemenu)
		{
		case 1:
			AddModelPC();
			break;

		case 2:
			ChangeModelPC();
			break;
		case 3:
			DeleteModelPC();
			break;

		case 4:
			ReadModelPC();
			break;
		case 5:
			ReadHistoryBuying();
			break;
		case 6:
			Close();

			break;
		default:
			exit(1);
			break;
		}
	}
}




