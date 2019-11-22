#include <iostream>
#include <string.h>
#include <malloc.h>
#define max 150

using namespace std;

typedef struct typenode *typeptr;
struct isi
{
	char antrian[10], nama[50], penyakit[40];
	int umur;
};

struct typenode
{
	isi info;
	typeptr next;
};

typeptr awal, akhir;

void buatlistbaru();
int listkosong();
void sisipnode(isi IB);
void bacamaju();
void input();
main()
{
	int menu;
	string kembali;
	buatlistbaru();
	do
	{
		cout << "Daftar Pasien RS Nakula" << endl;
		cout << "***********************";
		cout << "\n1. Masukkan data";
		cout << "\n2. Tampilkan Antrian";
		cout << "\n3. Keluar";
		cout << "\nPilih : ";
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			input();
			break;

		case 2:
			bacamaju();
			break;

		case 3:
			exit(3);
			break;
		}
		do
		{
			cout << "\nIngin kembali ke menu?y/n : ";
			cin >> kembali;
			system("cls");
		} while ((kembali != "y" && kembali != "Y") && (kembali != "n" && kembali != "N"));
	} while (kembali == "y" || kembali == "Y");
}

void input()
{
	string tambah;
	int i;
	isi data[max];
	i = 0;
	cout << "Masukkan Data Antrian\n";
	cout << "***********************\n";
	do
	{
		cout << "No. Antrian 	: ";
		cin.ignore();
		cin.getline(data[i].antrian, 10);
		cout << "Nama 	 	: ";
		cin.getline(data[i].nama, 50);
		cout << "Penyakit 	: ";
		cin.getline(data[i].penyakit, 40);
		cout << "Umur	 	: ";
		cin >> data[i].umur;
		sisipnode(data[i]);
		i++;
		do
		{
			cout << "\nTambah data?y/n : ";
			cin >> tambah;
		} while ((tambah != "y" && tambah != "Y") && (tambah != "n" && tambah != "N"));
	} while (tambah == "y" || tambah == "Y");
}

void buatlistbaru()
{
	typeptr list;
	list = NULL;
	awal = list;
	akhir = list;
}

int listkosong()
{
	if (awal == NULL)
		return 1;
	else
		return 0;
}

void sisipnode(isi IB)
{
	typeptr NB, bantu;
	NB = (typenode *)malloc(sizeof(typenode));
	NB->info = IB;
	NB->next = NULL;
	if (listkosong())
	{
		awal = NB;
		akhir = NB;
	}
	else if (strcmp(IB.antrian, awal->info.antrian) <= 0)
	{
		NB->next = awal;
		awal = NB;
	}
	else if (IB.umur > 60)
	{
		NB->next = awal;
		awal = NB;
	}
	else
	{
		bantu = awal;
		while (bantu->next != NULL && strcmp(IB.antrian, bantu->next->info.antrian) > 0)
			bantu = bantu->next;
		NB->next = bantu->next;
		bantu->next = NB;
		if (strcmp(IB.antrian, akhir->info.antrian) > 0)
			akhir = NB;
	}
}

void bacamaju()
{
	typeptr bantu;
	bantu = awal;
	cout << "Daftar Antrian\n";
	cout << "**************\n";
	while (bantu != NULL)
	{
		cout << "No. Antrian : " << bantu->info.antrian << endl;
		cout << "Nama        : " << bantu->info.nama << endl;
		cout << "Penyakit    : " << bantu->info.penyakit << endl;
		cout << "Umur        : " << bantu->info.umur << endl;

		bantu = bantu->next;
		cout << endl;
	}
}
