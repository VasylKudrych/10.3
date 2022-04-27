#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Friend
{
	string prizv;
	string name;
	string telephone;
	int date[3];
};

void enter_save(char* fname);
void load_print(char* fname);
void month_find(char* fname, char* fmonth);

int main()
{
	char fname[61];
	char fmonth[151];
	char ch;
	do
	{
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - пошук людей за їх місяцем народження" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> ch;
		cout << endl << endl << endl;
		switch (ch)
		{
		case '0':
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		case '1':
			cout << " [1] - введення даних з клавіатури" << endl;
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			enter_save(fname);
			break;
		case '2':
			cout << " [2] - вивід даних на екран" << endl;
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			load_print(fname);
			break;
		case '3':
			cout << "[3] - пошук людей за їх місяцем народження" << endl;
			cin.get();
			cin.sync();
			cout << "Enter Month: "; cin.getline(fmonth, sizeof(fmonth));
			month_find(fname, fmonth);
			break;
		default:
			cout << endl;
			cout << "Виберіть дію:" << endl << endl;
			cout << " [1] - введення даних з клавіатури" << endl;
			cout << " [2] - вивід даних на екран" << endl;
			cout << " [3] - пошук людей за їх місяцем народження" << endl;
			cout << " [0] - вихід та завершення роботи програми" << endl << endl;
			cout << "Введіть значення: "; cin >> ch;
			cout << endl << endl << endl;
		}
	}
	while (ch != '0');
	return 0;
}

void enter_save(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Friend friends;
	char ch;
	do
	{
		cout << endl;
		cout << "прізвище: "; cin.sync();
		cin >> friends.prizv;
		cout << " ім'я: "; cin.sync();
		cin >> friends.name;
		cout << "телефон: "; cin.sync();
		cin >> friends.telephone;
		cout << " День народження: "; cin.sync();
		cin >> friends.date[0];
		cout << " Місяць народження: "; cin.sync();
		cin >> friends.date[1];
		cout << " Рік народження: "; cin.sync();
		cin >> friends.date[2];

		if (!f.write((char*)&friends, sizeof(Friend)))
		{
			cerr << "Error writing file. " << endl;
		}
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch 'y');
}

void load_print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Friend friends;
	while (f.read((char*)&friends, sizeof(Friend)))
	{
		cout << endl;
		cout << "прізвище: " << friends.prizv << endl;
		cout << " ім'я: " << friends.name << endl;
		cout << "телефон: " << friends.telephone << endl;
		cout << " День народження: " << friends.date[0] << endl;
		cout << " Місяць народження: " << friends.date[1] << endl;
		cout << " Рік народження: " << friends.date[2] << endl;
	}
}

void month_find(char* fname, char* fmonth)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Friend friends;
	while (f.read((char*)&friends, sizeof(Friend)))
	{
		if (friends.date[1] == fmonth)
		{
			cout << endl;
			cout << "Found Friend With Month (" << fmonth << ") :" << endl;
			cout << endl;
			cout << "прізвище: " << friends.prizv << endl;
			cout << " ім'я: " << friends.name << endl;
			cout << "телефон: " << friends.telephone << endl;
			cout << " День народження: " << friends.date[0] << endl;
			cout << " Місяць народження: " << friends.date[1] << endl;
			cout << " Рік народження: " << friends.date[2] << endl;
		}
		else
		{
			cout << "...";
			cout << endl;
		}
	}
}
