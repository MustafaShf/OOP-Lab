#include<iostream>
using namespace std;

void growArr(int *&ptr,int size,int value)
{
	int *temp = new int[size + 1];
	int i = 0;
	for (; i < size; i++)
	{
		*(temp + i) = *(ptr + i);
	}
	*(temp + i) = value;
	delete[]ptr;
	ptr = temp;
	temp = nullptr;
	
}
void shrink(int *&ptr, int size)
{
	int *temp = new int[size-1];
	int i = 0;
	for (; i < size-1; i++)
	{
		*(temp + i) = *(ptr + i);
	}
	
	delete[]ptr;
	ptr = temp;
	temp = nullptr;

}

int main()
{
	int n;
	int value;
	cout << "Enter the size of array: ";
	cin >> n;
	int *ptr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter Values for array";
		cin>>*(ptr + i);
	}
	for (int i = 0; i < n; i++)
	{
		cout << *(ptr + i)<<" ";
	}

	cout << "Now time to grow Array. Enter Value: ";
	cin >> value;
	growArr(ptr, n, value);
	cout << "Your Growed Array: "<<endl;
	for (int i = 0; i < n+1; i++)
	{
		cout << *(ptr + i) << " ";
	}
	cout << endl;
	cout << "Your Shrnk Array: " << endl;
	cout << "Array Shrinked by 1"<<endl;
	for (int i = 0; i < n ; i++)
	{
		cout << *(ptr + i) << " ";
	}






	delete[]ptr;



	
	system("pause");


}