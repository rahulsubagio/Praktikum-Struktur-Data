#include <iostream>

using namespace std;

/*void misteril(char *);

int main()
{
	char string[] = "characters";
	cout<<"string sebelum proses adalah "<<string<<endl;
	misteril(string);
	cout<<"string setelah proses adalah "<<string;
}

void misteril(char *s)
{
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s-= 32;
			++s;
		}
	}
}*/

int misteril(const char *);

int main()
{
	char string[80];
	cout<<"ketik sebuah string : "; cin>>string;
	cout<<" "<<misteril(string);
}

int misteril(const char *s)
{
	int x=0;
	for ( ; *s != '\0'; s++)
	{
		++x;
	}
	return x;
}
