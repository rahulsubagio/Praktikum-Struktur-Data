#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct typequeue *ptrqueue;

struct data
{
	char kode[10], nama[50], dosen[50];
};

struct typequeue
{
	data info;
	ptrqueue next;
};

data mk;

//queue
ptrqueue qdepan, qbelakang;
void buatqueue();
int queuekosong();
void enqueue(data IB);
void dequeue();
void cetakqueue();

//archive queue
ptrqueue qarchive_depan, qarchive_belakang;
void buat_archivequeue();
int archive_queuekosong();
void archive_enqueue(data IB);
void archive_dequeue();
void archive_cetakqueue();

int main()
{
	int menu;
	bool ulang = false;
	char getchar;
	buatqueue();
	do
	{
		system("cls");
		cout << "::::: Data MK dengan Record :::::\n\n";
		cout << " 1. Tambah Data" << endl;
		cout << " 2. Cetak Data" << endl;
		cout << " 3. Ambil Data" << endl;
		cout << " 4. Data Tersimpan" << endl;
		cout << " 5. Exit" << endl;
		cout << "\nPilih : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("cls");
			cout << "::::: Tambah Data :::::\n\n";
			cin.ignore();
			cout << "Kode MK \t: "; cin.getline(mk.kode, 10);
			cout << "Nama MK \t: "; cin.getline(mk.nama, 50);
			cout << "Dosen MK \t: "; cin.getline(mk.dosen, 50);
			enqueue(mk);
			ulang = true;
			break;

		case 2:
			system("cls");
			cout << "::::: Daftar Mata Kuliah :::::\n\n";
			cetakqueue();
			cout << endl;
			cout << "Kembali Kemenu ? : "; cin >> getchar;
			ulang = false;
			break;

		case 3:
			system("cls");
			dequeue();
			cout << "\n::::: Data berhasil diambil :::::\n\n";
			cout << "Kembali Kemenu ? : "; cin >> getchar;
			ulang = false;
			break; 

		case 4:
			system("cls");
			cout << "::::: Data Tersimpan :::::\n\n";
			archive_cetakqueue();
			cout << endl;
			cout << "Kembali Kemenu ? : "; cin >> getchar;
			ulang = false;
			break;

		case 5:
			exit(0);
			break;
		}
	} while (ulang == true || getchar == 'y');
}

//=============================
//queue

void buatqueue()
{
	qdepan = (typequeue *)malloc(sizeof(typequeue));
	qdepan = NULL;
	qbelakang = qdepan;
}

int queuekosong()
{
	if (qdepan == NULL)
		return (1);
	else
		return (0);
}

void enqueue(data IB)
{
	ptrqueue NB;
	NB = (typequeue *)malloc(sizeof(typequeue));
	NB->info = IB;
	if (qdepan == NULL)
		qdepan = NB;
	else
		qbelakang->next = NB;
	qbelakang = NB;
	qbelakang->next = NULL;
}

void dequeue()
{
	ptrqueue hapus;
	if (queuekosong())
	{
		cout << "Queue masih kosong !";
	}
	else
	{
		hapus = qdepan;
		qdepan = hapus->next;
		archive_enqueue(hapus->info);
		free(hapus);
	}
}

void cetakqueue()
{
	int i = 1;
	ptrqueue bantu;
	bantu = qdepan;
	do
	{
		cout << "Data MK ke - " << i << endl;
		cout << "Kode MK \t: " << bantu->info.kode << endl;
		cout << "Nama MK \t: " << bantu->info.nama << endl;
		cout << "Dosen MK \t: " << bantu->info.dosen << endl << endl;
		bantu = bantu->next;
		i++;
	} while (bantu != NULL);
}

//=============================
//queue archive

void buat_archivequeue()
{
	qarchive_depan = (typequeue *)malloc(sizeof(typequeue));
	qarchive_depan = NULL;
	qarchive_belakang = qarchive_depan;
}

int archive_queuekosong()
{
	if (qarchive_depan == NULL)
		return (1);
	else
		return (0);
}

void archive_enqueue(data IB)
{
	ptrqueue NB;
	NB = (typequeue *)malloc(sizeof(typequeue));
	NB->info = IB;
	if (qarchive_depan == NULL)
		qarchive_depan = NB;
	else
		qarchive_belakang->next = NB;
	qarchive_belakang = NB;
	qarchive_belakang->next = NULL;
}

void archive_dequeue()
{
	ptrqueue hapus;
	if (queuekosong())
	{
		cout << "Queue masih kosong !";
	}
	else
	{
		hapus = qarchive_depan;
		qarchive_depan = hapus->next;
		free(hapus);
	}
}

void archive_cetakqueue()
{
	int i = 1;
	ptrqueue bantu;
	bantu = qarchive_depan;
	do
	{
		cout << "Data ke - " << i << endl;
		cout << "Kode MK \t: " << bantu->info.kode << endl;
		cout << "Nama MK \t: " << bantu->info.nama << endl;
		cout << "Dosen MK \t: " << bantu->info.dosen << endl << endl;
		bantu = bantu->next;
		i++;
	} while (bantu != NULL);
}
