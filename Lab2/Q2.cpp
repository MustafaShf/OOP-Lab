#include<iostream>
using namespace std;

void matrixInitializer(int**& ptr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter Value for [" << i << "][" << j << "] : ";
			cin >> ptr[i][j];
		}
	}
}
void transpose(int**& ptr, int& row, int& col)
{
	int** temp = 0;
	temp = new int* [col];
	for (int i = 0; i < col; i++)
	{
		*(temp + i) = new int[row];
	}
	int l = 0;
	int m = 0;
	for (int i = 0; i < col; i++)
	{
		m = 0;
		for (int j = 0; j < row; j++)
		{
			temp[l][m] = ptr[j][i];
			m++;
		}
		l++;
	}
	for (int i = 0; i < row; i++) {
		delete[] ptr[i];
	}
	delete[] ptr;
	ptr = temp;
	int tempVal = row;
	row = col;
	col = tempVal;

}


int main()

{
	int row = 0;
	int cols = 0;
	int** ptr = 0;
	cout << "Enter Num of rows: ";
	cin >> row;
	cout << "Enter Num of Cols: ";
	cin >> cols;
	ptr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(ptr + i) = new int[cols];
	}
	matrixInitializer(ptr, row, cols);
	cout << "Original" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ptr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "Transpose" << endl;
	transpose(ptr, row, cols);
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
	return 0;
}