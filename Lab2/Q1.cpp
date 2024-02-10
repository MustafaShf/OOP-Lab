#include<iostream>
using namespace std;

void matrixInitializer(int** &ptr, int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ptr[i][j] = rand()%20+1;
		}
	}
}
int SumCalculator(int**& ptr, int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum+=ptr[i][j];
		}
	}
	return sum;
}


int main()
	
{
	int row = 0;
	int cols = 0;
	int** ptr = 0;
	cout << "Enter Num of rows: " ;
	cin >> row;
	cout << "Enter Num of Cols: ";
	cin>> cols;
	ptr = new int* [row];
	for(int i=0;i<row;i++)
	{
		*(ptr + i) = new int[cols];
	}
	matrixInitializer(ptr, row, cols);
	int totalSum = SumCalculator(ptr, row, cols);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ptr[i][j] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < row; i++)
	{
		delete[]ptr[i];
		ptr[i] = nullptr;
	}
	delete[]ptr;
	cout << "Total Sum: " << totalSum;
	return 0;
}