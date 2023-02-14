#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void ChangeMinRow(int** a,int& n,const int rowCount, const int colCount, int min, int max);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -30;
	int High = 30;
	int rowCount; cout << "length = "; cin >> rowCount;
	int colCount; cout << "width = "; cin >> colCount;
	int n;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	ChangeMinRow(a, n, rowCount, colCount, 0, 0);
	
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



void ChangeMinRow(int** a, int& n, const int rowCount, const int colCount, int min, int max)
{
	for (int i = 1; i < rowCount; i+=2) {
		min = a[i][0];
		max = a[i][0];

		int kmax = 0;
		int kmin = 0;
		for (int j = 1; j < colCount; j++ ){
			if (a[i][j] > max){
				max = a[i][j];
				kmax = j;
			}
			if (a[i][j] < min) {
				min = a[i][j];
				kmin = j;
			}
		
		}
	
		a[i][kmax] = min;
		a[i][kmin] = max;

	}
}
