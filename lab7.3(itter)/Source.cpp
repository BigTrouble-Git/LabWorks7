#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Search(int** a, const int rowCount, const int colCount, int k);
int Sum(int** a, const int rowCount, const int colCount);
void sort(int** a, const int rowCount, const int colCount);
void change(int** a, const int row1, const int row2, const int colCount);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = 20;
	int rowCount; cout << "lenght = "; cin >> rowCount;
	int colCount; cout << "width = "; cin >> colCount;
	int k = -1;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Search(a, rowCount, colCount, k);
	cout << endl;
	sort(a, rowCount, colCount);

	Print(a, rowCount, colCount);


	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
//Part 1
int Search(int** a, const int rowCount, const int colCount, int k)
{
	

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++) {
			if (a[i][j] == 0) {
				k = j;
				break;
			}
		}
	}
	if (k >= 0) {
		cout << " Null is in " << k + 1 << " column" << endl;
	}
	else cout << "There is any null" << endl;
		return 0;
}
//Part 2




int Sum(int** a, const int rowCount, const int colCount) {
	int sumRaw = 0;

	for (int j = 0; j < colCount; j++)
		if (a[rowCount][j] < 0 && a[rowCount][j] % 2 == 0)
			sumRaw += a[rowCount][j];

	return sumRaw;

}

void Change(int** a, const int raw1, const int raw2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[raw1][j];
		a[raw1][j] = a[raw2][j];
		a[raw2][j] = tmp;
	}
}


void sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if (Sum(a, i1, colCount) < Sum(a, i1 + 1, colCount))
				Change(a, i1, i1 + 1, colCount);

}


