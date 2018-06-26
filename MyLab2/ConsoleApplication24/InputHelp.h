#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int InputNum(int min, int max, string info);

// ввод информации
string InputInfo(string info);

// проверка символа на корректность в имени файла
bool CorrectSymbol(char c);


// проверка имени файла на коректность
bool CorrectName(string name);

// ввод имени файла
string InputFileName();





