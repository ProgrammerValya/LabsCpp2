#include "stdafx.h"
#include "ComputerUtils.h"
#include "Computer.h"
template<class Type>
void ComputerUtils<Type>::Remove(int numb)
{

	if (numb != 0)
		vect.erase(vect.begin() + numb - 1);

}
template<class Type>
void ComputerUtils<Type>::Add(Type & elem)
{
	vect.push_back(elem);
}

template<class Type>
int ComputerUtils<Type>::size()
{
	return vect.size();
}

template<class Type>
bool ComputerUtils<Type>::Is_empty()
{
	return (vect.size() == 0);
}

template<class Type>
void ComputerUtils<Type>::OutputFile(void(*f)(Type, ofstream&), string newfname)
{
	ofstream fout(newfname, ios::binary);  //создаем поток. ios binary гарантирует что символы новой строки будут обработаны. Режим бинарный файл
	if (fout)
	{
		int i = vect.size();
		//(char*)&i-делаем стркоу байтов, чтобы отдать, открытому потоку в бинарном режиме
		//sizeof(int)-ограничиваем число уходящих в поток байтов 
		fout.write((char*)&i, sizeof(int));  // записываем в файл размер для последующего считывания. 

		vector<Type>::const_iterator pos;
		for (pos = vect.begin(); pos != vect.end(); ++pos) //записываем данные всего вектора
		{
			f(*pos, fout);
		}
	}
}

// вывод на экран
template<class Type>
void ComputerUtils<Type>::OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)())
{
	vector<Type>::const_iterator pos;
	Header();
	int count = 1;
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << setw(4) << setiosflags(ios::left) << count << "|";
		f(*pos);
		++count;
	}

}

// вывод из файла
template<class Type>
bool ComputerUtils<Type>::ReadFromFile(Type(*f)(ifstream&), string newfname)
{
	std::ifstream input;

	input.open(newfname, ios::binary);

	if (!input)
	{
		cout << "Не удалось открыть файл" << endl;
		return false;
	}
	else
	{
		int size;
		Type elem;
		input.read((char*)&size, sizeof(int)); // считали размер
		for (int i = 0; i < size; i++)
		{
			vect.push_back(f(input));
		}

		input.close();
		return true;
	}
}

// ввод с экрана
template<class Type>
void ComputerUtils<Type>::ReadFromScreen(Type(*f)())
{
	int n;
	Type elem;
	do
	{
		vect.push_back(f());
		n = InputNum(0, 1, "Добавить элемент? (1 - да, 0 - нет)\nВаш выбор: ");
	} while (n != 0);
}

// линейный поиск
template<class Type>
vector<Type> ComputerUtils<Type>::LinearySearch(Type search_elem, bool(*Equal)(Type, Type))
{
	vector<Type> NewVect;
	for (auto iter = vect.begin(); iter != vect.end(); iter++)
	{
		if (Equal(search_elem, *iter))
			NewVect.push_back(*iter);
	}
	return NewVect;
}


// линейный поиск возвращает номер эл-та одинакового с search_elem если одинаковый не найден возвращает -1
template<class Type>
int ComputerUtils<Type>::LinearySearchElem(Type search_elem)
{
	for (int i = 0; i < vect.size(); i++)
	{
		if (search_elem == vect[i])
			return i;
	}
	return -1;
}

// бинарный поиск
// int(*Compare)(Type, Type, int) - указатель на функцию, которая сравнивает искомый эл-т с текущим по type_search 
// bool(*Equal)(Type, Type, int) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим по type_search
template<class Type>
vector<Type> ComputerUtils<Type>::BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type))
{
	vector<Type> NewVect;
	sort(vect.begin(), vect.end(), Compare);

	int left = 0;
	int right = vect.size();
	auto index = std::lower_bound(vect.begin(), vect.end(), find_element, Compare);


	while ((index != vect.end()) && Equal(*index, find_element))
	{
		NewVect.push_back(*index);
		index++;
	}

	return NewVect;
}



