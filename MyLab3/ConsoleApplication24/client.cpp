#include "stdafx.h"

#include "Client.h"

#include "InputHelp.h"
#include "BuyingComputer.h"
#include "Computer.h"
#include "User.h"

// класс клиента

// конструктор
Client::Client(string _name_client, string _filename_model_PC, string _filename_history_buy) :User(_filename_model_PC, _filename_history_buy)
{
	name_client = _name_client;

}

// поиск с покупкой ( главная идея что поле кол-во экземпляров должно уменьшатся при покупке)
void Client::BuyingModelPC()   
{
	Computer c;

	bool(*compare)(Computer, Computer) = NULL;
	bool(*sort)(Computer, Computer) = NULL;
	//в множество запишем все найденные по запросу клиента компьютеры
	vector<Computer> subset;
	//выбираем по какому критерию искать компьютер
	subset = LookModelPCToCriteria();
	
	if (subset.size() != 0)
	{
		//выводим множество на экран
		//vectModelComputer.OutputScreen(subset, Computer::OutputScreenComputer, Computer::OutputScreenHeaderComputer);
		int num = InputNumInt(0, subset.size(), "Выберите номер компьютера ( 0 - если передумали выбирать): ");
		if (num != 0)
		{
			// поиск номера одинакового эл-та с выбранным  
			int n = vectModelComputer.LinearySearchElem(subset[num - 1]);
			//определяем количетсво экзмепляров данной модели
			int count_ekz = vectModelComputer.vect[n].get_Count();
			// если кол-во экземпляров больше 0 (они есть в наличии)
			if (count_ekz > 0)
			{
				// вводим "купленный компьютер"  с консоли (сразу передаем имя клиента и код компа)  //отдним методом покупки в компюьтере
				BuyingComputer buyComputer = BuyingComputer::BuyingComputer(name_client, vectModelComputer.vect[num - 1].get_Code());
				// добавление в список покупок (в историю покупок)
				vectBuyingComputer.Add(buyComputer); //останется
													 // уменьшение кол-ва экземпляров на 1
				vectModelComputer.vect[num - 1].set_Count(count_ekz - 1);
			}
			else
				cout << "Нет экземпляров в наличии!!" << endl;
		}
		else
			cout << "Покупка отменена!" << endl;
	}
	else
		cout << "Элементы не найдены" << endl;
}



// меню
void Client::Menu()
{

	int changemenu = 0;
	while (changemenu != 4)
	{
		cout << " --------------------Меню клиента---------------------  " << endl;
		cout << "1 - Поиск модели ПК" << endl;
		cout << "2 - Покупка модели ПК" << endl;
		cout << "3 - Посмотреть все модели ПК" << endl;
		cout << "4 - Выход" << endl;

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


