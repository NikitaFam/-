#include <iostream>
#include <clocale>
using namespace std;
// ����������� ��� �������, ������ �� ���������� ����� ��� ������ �������
void printArray(int** array, const int rows, const int cols)//������� � ���������� �� ��������� �������, � ����������� ������ � �������

{
	for (int i = 0; i < rows; i++)//��������� ���� �� �������
	{
		for (int j = 0; j < cols; j++)//������� �� ������� 
		{
			cout << array[i][j] << " ";//��������� ������
		}
		cout << endl;//������� ������
	}
}
void sortArray(int** array, const int rows, const int cols)//������ ����������, � ����������, ����������� ���������, ������ � �������
{

	//������� ��������������� ���������� ������ � ����������� ��������� ������ ���������� ����� � �������� �������
	int* sumTempArray = new int[rows];

	//�������� �� ��������� �������, ������� ����� ������������� ������ ��������� � ������
	for (int i = 0; i < rows; i++)//���������� ����
	{
		int sumRowResult = 0;
		for (int j = 0; j < cols; j++)//��������� ���� �� ��������
		{
			if (array[i][j] > 0 && array[i][j] % 2 == 0)//������������� ������  �� ������� > 0 � �������� �� 2
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
				// ����� ������� ����� � �������� ������� �� �������� �� ���������������� �������
				int* temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				// ����� ������� ��������� � ��������������� �������
				int temp1 = sumTempArray[j];
				sumTempArray[j] = sumTempArray[j + 1];
				sumTempArray[j + 1] = temp1;
			}
		}
	}
	// ������ ������
	delete[] sumTempArray;
}
// ������� ������ ��� ������� ���������
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
	cout << "�� 6 ��������� �������� ������ " << endl;
	cout << "������� ���������� ����� ������� � = ";
	cin >> k;
	while (k <= 0 || cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "���������� ���: ";
		cin >> k;
	}

	cout << "������� ���������� �������� ������� m = ";
	cin >> m;
	while (m <= 0 || cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "���������� ���: ";
		cin >> m;
	}
	// �������� �������
	int** arr = new int* [k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = new int[m];
	}
	//���� �������
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "������� arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
			while (cin.fail() || cin.get() != '\n')
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "���������� ���: ";
				cin >> arr[i][j];
			}
		}
	}
	//����� �������

	cout << "����������� ������: " << endl;
	printArray(arr, k, m);
	/*for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	// ����� ���������� ����� ��� ������� ���������

	cout << "���������� ��������� ���������: \n" << noZeroRows(arr, k, m) << "\n" << endl;

	// ���������� 

	sortArray(arr, k, m);

	//����� �������
	cout << "������ ����� ����������: " << endl;
	printArray(arr, k, m);

	/*for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	//������� ������
	for (int i = 0; i < k; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}