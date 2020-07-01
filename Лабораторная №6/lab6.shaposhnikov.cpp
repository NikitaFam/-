#include <iostream>
#include <clocale>
using namespace std;
// процедурный тип функции, ничего не возвращает нужен для вывода матрицы
void printArray(int** array, const int rows, const int cols)//функция с указателем на указатель массива, и параметрами строки и столбцы

{
	for (int i = 0; i < rows; i++)//организую цикл по строкам
	{
		for (int j = 0; j < cols; j++)//перебор по ячейкам 
		{
			cout << array[i][j] << " ";//заполняем массив
		}
		cout << endl;//пропуск строки
	}
}
void sortArray(int** array, const int rows, const int cols)//фунция сортировки, в параметрах, указательна указатели, строки и колонки
{

	//Создаем вспомогательный одномерный массив с количеством элементов равным количеству строк в основном массиве
	int* sumTempArray = new int[rows];

	//Проходим по основному массиву, считаем сумму положительных четных элементов в строке
	for (int i = 0; i < rows; i++)//организуем цикл
	{
		int sumRowResult = 0;
		for (int j = 0; j < cols; j++)//организую цикл по колонкам
		{
			if (array[i][j] > 0 && array[i][j] % 2 == 0)//просматриваем массив  по условию > 0 и делиться на 2
			{
				sumRowResult += array[i][j];
			}
		}
		sumTempArray[i] = sumRowResult;
	}
	for (int i = 1; i < rows; ++i)
	{
		for (int j = 0; j < rows - i; j++)
		{
			if (sumTempArray[j] > sumTempArray[j + 1])
			{
				// Обмен местами строк в основном массиве по индексам из вспомогательного массива
				int* temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				// Обмен местами элементов в вспомогательном массиве
				int temp1 = sumTempArray[j];
				sumTempArray[j] = sumTempArray[j + 1];
				sumTempArray[j + 1] = temp1;
			}
		}
	}
	// чистим память
	delete[] sumTempArray;
}
// считаем строки без нулевых элементов
int noZeroRows(int** array, const int rows, const int cols)
{
	int noZeroRowsCount = 0;

	for (int i = 0; i < rows; i++)
	{
		bool catchZeroElement = 0;
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] == 0)
			{
				catchZeroElement = 1;
				continue;
			}
		}
		if (!catchZeroElement)
			noZeroRowsCount++;
	}
	return noZeroRowsCount;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int k, m;
	cout << "ЛР 6 Обработка числовых матриц " << endl;
	cout << "Введите количество строк матрицы к = ";
	cin >> k;
	while (k <= 0 || cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Попробуйте еще: ";
		cin >> k;
	}

	cout << "Введите количество столбцов матрицы m = ";
	cin >> m;
	while (m <= 0 || cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Попробуйте еще: ";
		cin >> m;
	}
	// создание матрицы
	int** arr = new int* [k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = new int[m];
	}
	//Ввод массива
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "Введите arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
			while (cin.fail() || cin.get() != '\n')
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "Попробуйте еще: ";
				cin >> arr[i][j];
			}
		}
	}
	//Вывод массива

	cout << "Изначальный массив: " << endl;
	printArray(arr, k, m);
	/*for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	// вывод количества строк без нулевых элементов

	cout << "Количество ненулевых элементов: \n" << noZeroRows(arr, k, m) << "\n" << endl;

	// сортировка 

	sortArray(arr, k, m);

	//Вывод массива
	cout << "Массив после сортировки: " << endl;
	printArray(arr, k, m);

	/*for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	//Очистка памяти
	for (int i = 0; i < k; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}