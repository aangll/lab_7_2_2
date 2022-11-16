#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int k, const int n, const int Low, const int High, int i, int j)
{
	y[i][j] = Low + rand() % (High - Low + 1);

	if (j <n - 1)
		Create(y, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(y, k, n, Low, High, i + 1, 0);
}

void Print(int** y, const int k, const int n, int i, int j)
{
	cout << setw(4) << y[i][j];
	if (j < n - 1)
		Print(y, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(y, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;

}

int iMax(int** y, int k, int n, int i, int j, int max, int imax)
{
	if (y[i][j] > max) {
		max = y[i][j];
		imax = j;
	}
	if (j < n - 1)
		iMax(y, k, n, i, j + 1, max, imax);
	else
		return imax;
}


int iMin(int** y, int k, int n, int i, int j, int min, int imin)
{
	if (y[i][j] < min) {
		min = y[i][j];
		imin = j;
	}
	if (j < n-1) 
		iMin(y, k, n, i, j + 1, min, imin);
	else
		return imin;
}

void Change(int** y, int k, int n, int i, int max, int imax, int min, int imin)
{
	int IndexOfMax = iMax(y, k, n, i, 0, max, imax);
	int IndexOfMin = iMin(y, k, n, i-1, 0, min, imin);

	int tmp = y[i][IndexOfMax];
	y[i][IndexOfMax] = y[i - 1][IndexOfMin];
	y[i - 1][IndexOfMin] = tmp;

	if (i < k-1)
		Change(y, k, n, i + 2, max, imax, min, imin);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 2;
	int High = 50;
	int k;
	int n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int i = 0;
	int j = 0;
	int** y = new int* [k];
	for (int i = 0; i < k; i++)
		y[i] = new int[n];
	int max = -123;
	int imax = 0;
	int min = 123;
	int imin = 0;
	Create(y, k, n, Low, High, i, j);
	cout << "create ok" << endl;
	Print(y, k, n, i, j);
	cout << "print ok" << endl;
	iMax(y, k, n, i, j, max, imax);
	cout << "max ok" << endl;
	iMin(y, k, n, i, j, min, imin);
	cout << "min ok" << endl;
	Change(y, k, n, 1, max, imax, min, imin);
	cout << "Change ok" << endl;
	Print(y, k, n, i, j);
}
