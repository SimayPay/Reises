#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


struct Reises
{
	int number = 0;
	string finish_place;
	int time_1;
	int time_2;
};
Reises list[100];



//Добавление рейсов..
int AddReis(int last_numb)
{
	string path("Reises.txt");
	ofstream file(path, ofstream::app);

	cout << "Добавление рейса.." << endl;
	cout << "Введите количество рейсов: ";
	int n;
	cin >> n;
	for (int numb = last_numb; numb < n; numb++)
	{
		if (file.is_open())
		{
			cout << "Введите пункт назначения, время отбытия, время прибытия: ";
			cout << "Рейс №" << numb << endl;
			list[numb].number = numb;
			cin >> list[numb].finish_place >> list[numb].time_1 >> list[numb].time_2;
			file << list[numb].number << endl << list[numb].finish_place << endl << list[numb].time_1 << endl << list[numb].time_2 << endl;
			last_numb = numb + 1;
		}
		else {
			cout << "error!" << endl;
		}
	}
	file.close();
	return last_numb;
}

//Просмотр рейсов..
void Read()
{
	cout << "Просмотр рейсов.." << endl;
	string line;
	string path("Reises.txt");
	ifstream file(path);

	if (file.is_open())
	{

		while (!file.eof())
		{
			file >> line;
			cout << line << endl;
			line.clear();
		}
		cout << endl;
	}
	else
	{
		cout << "error!" << endl;
	}
	file.close();
}

//Линейный поиск..
void LinearSearch()
{

}

//Quicksort сортировка рейсов..
void Quicksort(int b, int e)
{
	int l = b, r = e, cur_time;
	cin >> cur_time;

	while (l <= r)
	{
		while (list[l].time_2 < cur_time)
		{
			l++;
		}
		while (list[r].time_2 > cur_time)
		{
			r--;
		}
		if (l <= r)
		{
			swap(list[l++].time_2, list[r--].time_2);
		}
	}
	if (b < r)
		Quicksort(b, r);
	if (e > l)
		Quicksort(l, e);
}

//Метод прямого выбора..
void DirectChoose(int last_numb)
{
	cout << "Введите пункт назначения: ";
	string finish_place;
	cin >> finish_place;
	cout << "Введите время прибытия: ";
	int cur_time;
	cin >> cur_time;

	for (int i = 0; i < last_numb; i++)
	{
		if ((list[i].finish_place == finish_place) && (list[i].time_2 < cur_time))
		{
			cout << list[i].number << endl << list[i].finish_place << ", " << list[i].time_1 << ", " << list[i].time_2 << endl;
		}
	}
}

//Двоичный поиск рейсов в отсортированном массиве..
void BinarSearch()
{

}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Выберите действие: 1)Добавление рейса; 2)Просмотр рейсов; 3)Линейный поиск; 4)Быстрая сортировка; 5)Метод прямого выбора; 6)Бинарный поиск;  7)Выход;";
	int n; cin >> n;
	int last_numb = 0;
	int b = 0, e = last_numb;
	while (n != 7)
	{
		switch (n)
		{
		case 1:
			AddReis(last_numb);
			break;
		case 2:
			Read();
			break;
		case 3:
			LinearSearch();
			break;
		case 4:
			Quicksort(b, e);
			break;
		case 5:
			DirectChoose(last_numb);
			break;
		case 6:
			BinarSearch();
			break;
		}
		cout << "Выберите действие: 1)Добавление рейса; 2)Просмотр рейсов; 3)Линейный поиск; 4)Быстрая сортировка; 5)Метод прямого выбора; 6)Бинарный поиск;  7)Выход;";
		cin >> n;

	}
}

