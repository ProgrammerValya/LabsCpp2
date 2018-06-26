#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
using namespace std;

// ввод информации
string InputInfo(string info);

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c);

// проверка имени файла на коректность
bool CorrectName(string name);

// ввод имени файла
string InputFileName();

// чтение строки из бинарного файла
string StringFromBinFile(ifstream& in);

// запись строки в бинарный файл
void StringInBinFile(ofstream& os, string str);

// ввод числа в диапозоне
int InputNumInt(int min, int max, string message);








