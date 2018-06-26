#include "stdafx.h"

#include "User.h"
#include "InputHelp.h"
#include "BuyingComputer.h"
#include "Computer.h"


// класс "User"
// конструктор. На вход поступают имя файла моделей компьютера, имя файла истории покупок
User::User(string _filename_model_PC, string _filename_history_buy)
{
	filename_model_PC = _filename_model_PC;
	filename_history_buy = _filename_history_buy;
	// записываем информацию из файлов в вектор с моделями компьютеров и в вектор с историеей покупок
	vectModelComputer.ReadFromFile(Computer::ReadComputerFromFile, filename_model_PC);
	vectBuyingComputer.ReadFromFile(BuyingComputer::ReadBuyingComputerFromFile, filename_history_buy);
}

//вывод списка моделей ПК с фильтрацией выбранному полю  
vector<Computer> User::LookModelPCToCriteria()
{
	Computer c;

	bool(*compare)(Computer, Computer) = NULL;
	bool(*sort)(Computer, Computer) = NULL;

	vector<Computer> subset;

	int numb = InputNumInt(1, 9, "Выберите тип поиска:\n 1 - по коду марки компьютера\n 2 - по название марки компьютера\n 3 - по типу процессора\n 4 - по частоте работы процессора \n 5 - по объему оперативной памяти \n 6 - по объему жесткого диска \n 7 - объему памяти видеокарты \n 8 - по стоимости компьютера \n 9 - по количеству экземпляров\n---> ");
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
		//выводим уже новое подмножество с фильтрацией по нужному полю
		vectModelComputer.OutputScreen(subset, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
	else
		cout << "Элементы не найдены" << endl;
	return subset;
}

// посмотреть модели PC
void User::ReadModelPC()
{
	vectModelComputer.OutputScreen(vectModelComputer.vect, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
}


// выход
void User::Close()
{
	vectModelComputer.OutputFile(Computer::WriteComputerToFile, filename_model_PC);
	vectBuyingComputer.OutputFile(BuyingComputer::WriteBuyingComputerToFile, filename_history_buy);
}

