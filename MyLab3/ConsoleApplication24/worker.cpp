#include "stdafx.h"

#include "worker.h"

#include "BuyingComputer.h"
#include "InputHelp.h"
#include "Computer.h"


Worker::Worker(string _filename_model_PC, string _filename_history_buy) :User(_filename_model_PC, _filename_history_buy)
{

}


// добавить модель PC. Модель добавляется в вектор компьютеров в Uses
void Worker::AddModelPC()
{
	vectModelComputer.Add(Computer::InputScreenComputer());
}

// изменить модель PC
void Worker::ChangeModelPC()
{
	if (vectModelComputer.Is_empty())
		cout << "Нет типов работ";
	else
	{
		vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
		int numb = InputNumInt(0, vectModelComputer.size(), "\nВведите номер изменяемой записи (0 - если передумали изменять): ");
		if (numb != 0)
		{
			Computer::ChangeComputer(vectModelComputer.vect[numb - 1]);
			/*vectModelComputer.OutputFile(Computer::WriteComputerToFile, filename_model_PC);*/ // можно перезаписывать после каждого изменения можно толко при выходе
			cout << "Запись изменена!" << endl;                                            // тогда нажатие на x не контролируется
		}
	}
}

// удалить модель PC
void Worker::DeleteModelPC()
{
	vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
	vectModelComputer.Remove(InputNumInt(0, vectModelComputer.size(), "Введите номер удаляемого элемента ( 0 - если передумали удалять): "));
}

// посмотреть историю покупок
void Worker::ReadHistoryBuying()
{
	vectBuyingComputer.OutputScreen(vectBuyingComputer.vect, BuyingComputer::OutputScreenBuyingComputer, BuyingComputer::OutputScreenHeaderBuyingComputer);
}

// меню
void Worker::Menu()
{

	int changemenu = 0;
	while (changemenu != 6)
	{

		cout << " --------------------Меню сотрудника---------------------  " << endl;
		cout << "1 - Добавить модель ПК" << endl;
		cout << "2 - Изменить модель ПК" << endl;
		cout << "3 - Удалить модель ПК" << endl;
		cout << "4 - Посмотреть модели ПК" << endl;
		cout << "5 - Посмотреть историю покупок" << endl;
		cout << "6 - Выход" << endl;
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




