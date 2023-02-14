#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}


void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}


void ChangeMinRow(int** a, int& n, const int rowCount, const int colCount, int& min, int& max, int i, int j, int& kmax, int& kmin)
{
	if (j < colCount)
	{
		if (a[i][j] > max) {
			max = a[i][j];
			kmax = j;
		}

		if (a[i][j] < min) {
			min = a[i][j];
			kmin = j;
		}
		ChangeMinRow(a, n, rowCount, colCount, min, max, i, j + 1, kmax, kmin);
	}

}


void Change(int** a, int& n, int& min, int& max, int kmin, int kmax, const int rowCount, int colCount, int i) {
	if (i < rowCount) {
		min = a[i][0];
		max = a[i][0];
		kmax = 0;
		kmin = 0;
		ChangeMinRow(a, n, rowCount, colCount, min, max, i, 1, kmax, kmin);

		a[i][kmax] = min;
		a[i][kmin] = max;
		Change(a, n, min, max, kmin, kmax, rowCount, colCount, i + 2);

	}
}





int main()
{
	srand((unsigned)time(NULL));
	int Low = -34;
	int High = 26;
	int rowCount; cout << "length = "; cin >> rowCount;
	int colCount; cout << "width = "; cin >> colCount;
	int n, min, max;
	
	int kmax = 0, kmin = 0;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);

	cout << endl;

	Print(a, rowCount, colCount, 0, 0);

	Change(a, n, min, max, kmin, kmax, rowCount, colCount, 1);

	Print(a, rowCount, colCount, 0, 0);


	return 0;
}
