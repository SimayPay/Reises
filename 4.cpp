#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream input("Reises.txt", ios::app);
ofstream output("Reises.txt", ios::app);

struct Reises
{
	int number;
	string place_finish;
	float time_1;
	float time_2;
};
Reises list[100];


//Добавление рейсов..
void AddReis()
{
	cout << "Adding reis..";
	cout << "Enter ammount of reises" << endl;
	int n = 0;
	cin >> n;
	if (input.is_open())
	{
		

	}
	else {
		cout << "error!" << endl;
	}
}

//Линейная сортировка рейсов..
void LinearSort()
{

}

//Quicksort сортировка рейсов..
void Quicksort()
{

}

//Сортировка прямого выбора..
void DirectSearch()
{

}

//Двоичный поиск рейсов в отсортированном массиве..
void BinarSearch()
{

}


int main()
{
	cout << "Выберите действие: ";
	int n;
	cin >> n;
	switch(n)
	{
		case 1:
			AddReis();
			break;
		case 2:
			LinearSort();
			break;
		case 3:
			Quicksort();
			break;
		case 4:
			DirectSearch();
			break;
		case 5:
			BinarSearch();
			break;
	}

}

