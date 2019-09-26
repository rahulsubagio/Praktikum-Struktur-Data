#include <iostream>
#define max 50

using namespace std;

int top = 0, stack[max];

void buatstack()
{
	stack[top] = 0;
}

void push()
{
	int N;
	cout << "Number : "; cin >> N;
	top++;
	stack[top] = N;
	stack[0] = top;
}

void pop()
{
	int IP;
	IP = stack[top];
	top--;
	stack[0] = top;
}

void cetak()
{
	int i = 1;
	while (i <= top)
	{
		cout << stack[i] << " ";
		i++;
	}
}

int main()
{
	int pilih; char y;
	buatstack();
	do
	{
		system("cls");
		cout << "Menu :\n 1. Push\n 2. POP\n 3. Cetak\nPilih : ";
		cin >> pilih;
		switch (pilih)
		{
			case 1:
				system("cls");
				push();
				break;
			case 2:
				system("cls");
				pop();
				break;
			case 3:
				system("cls");
				cetak();
				cout << endl << endl;
				system("pause");
				break;
		}
		y = 'y';
	} while (y == 'y');
}
