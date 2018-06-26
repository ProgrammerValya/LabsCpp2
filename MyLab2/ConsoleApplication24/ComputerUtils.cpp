
#include "stdafx.h"

#include "ComputerUtils.h"
#include "InputHelp.h"
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
void ComputerUtils<Type>::OutputFile(vector<Type> items, string(*f)(Type, int))
{
	string newfname = InputFileName();
	ofstream fout(newfname);
	if (fout)
	{
		vector<Type>::const_iterator pos;
		int count = 1;
		for (pos = items.begin(); pos != items.end(); ++pos)
		{
			fout << f(*pos, count) << ' ';
			count++;
		}
		cout << endl << "Файл заполнен" << endl;
		fout.close();
	}
	else
	{
		cout << "Ошибка при заполнении файла" << endl;
	}
}

template<class Type>
void ComputerUtils<Type>::OutputScreen(vector<Type> items, void(*f)(Type))
{
	vector<Type>::const_iterator pos;
	int count = 1;
	for (pos = items.begin(); pos != items.end(); ++pos)
	{
		cout << "Запись № " << count << endl;
		f(*pos);
		++count;
	}

}

template<class Type>
bool ComputerUtils<Type>::ReadFromFile(Type(*f)(ifstream &))
{
	string newfname = InputFileName();
	std::ifstream input;

	input.open(newfname);

	if (!input)
	{
		cout << "Не удалось открыть файл" << endl;
		return false;
	}
	else
	{
		while (!input.eof())
		{
			vect.push_back(f(input));
		}
		vect.erase(vect.begin() + vect.size() - 1);

		input.close();
		return true;
	}
}

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

//!!
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
