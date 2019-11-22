/* Implementasi Stack Menggunakan List */
#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct typestack *typeptr;
typedef struct typequeue *ptrqueue;
//typedef struct typearchive_stack *ptrarchive_stack;

struct data_penyewa
{
	char nama[50], ktp[20];
};

struct isi_data
{
	char plat[10], nama[50];
};
/*struct archive_stack{
	char plat[10], nama[50];
};*/

struct typequeue
{
	data_penyewa info_penyewa;
	ptrqueue next;
};
struct typestack
{
	isi_data info;
	typeptr next;
};
/*struct typearchive_stack{archive_stack info;
			ptrarchive_stack next;
};*/
isi_data data[50];
//archive_stack archive[50];
data_penyewa penyewa[50];
typeptr awalstack, akhirstack, awalarchive, akhirarchive;
//ptrarchive_stack awal_archive, akhir_archive;
void buat_stack();
int stack_kosong();

void push(isi_data IB);
void pop();
void cetak_stack();

//buat archive
void buat_archive();
int archive_kosong();

void push_archive(isi_data IB);
void pop_archive();
void cetak_archive();

//queue
ptrqueue qdepan, qbelakang;
void buatqueue();
int queuekosong();
void enqueue(data_penyewa IB);
void dequeue();
void cetakqueue();

//archive queue
ptrqueue qarchive_depan, qarchive_belakang;
void buat_archivequeue();
int archive_queuekosong();
void archive_enqueue(data_penyewa IB);
void archive_dequeue();
void archive_cetakqueue();

int main()
{
	int menu, jum_mobil, jum_penyewa;
	bool ulang = false;
	char getchar;
	buat_stack();
	buatqueue();
	buat_archive();
	do
	{
		system("clear");
		cout << "::::: Menu :::::" << endl
				 << endl;
		cout << " 1. Input Mobil" << endl;
		cout << " 2. Input Penyewa" << endl;
		cout << " 3. Daftar Mobil" << endl;
		cout << " 4. Daftar Antrian" << endl;
		cout << " 5. Keluarkan Mobil" << endl;
		cout << " 6. Mobil Yang Sedang Disewa" << endl;
		cout << " 7. Exit" << endl;
		cout << endl
				 << "Pilih : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			system("clear");
			cout << "Input Mobil" << endl
					 << endl;
			cout << "Masukkan jumlah mobil : ";
			cin >> jum_mobil;
			cin.ignore();
			for (int i = 0; i < jum_mobil; i++)
			{
				cout << endl;
				cout << "Data ke - " << i + 1 << endl;
				cout << "Masukkan nama mobil : ";
				cin.getline(data[i].nama, 50);
				cout << "Masukkan plat mobil : ";
				cin.getline(data[i].plat, 10);
				push(data[i]);
			}
			break;

		case 2:
			system("clear");
			cout << "Input Penyewa" << endl
					 << endl;
			cout << "Masukkan jumlah penyewa : ";
			cin >> jum_penyewa;
			cin.ignore();
			for (int i = 0; i < jum_penyewa; i++)
			{
				cout << endl;
				cout << "Data ke - " << i + 1 << endl;
				cout << "Masukkan nama penyewa : ";
				cin.getline(penyewa[i].nama, 50);
				cout << "Masukkan no identitas : ";
				cin.getline(penyewa[i].ktp, 20);
				enqueue(penyewa[i]);
			}
			break;

		case 3:
			system("clear");
			cout << "::::: Daftar Mobil yang tersedia :::::" << endl;
			cetak_stack();
			cout << endl;
			cin >> getchar;
			break;

		case 4:
			system("clear");
			cout << "::::: Daftar Antrian ::::: " << endl
					 << endl;
			cetakqueue();
			cout << endl;
			cin >> getchar;
			break;

		case 5:
			system("clear");
			cout << endl
					 << endl
					 << "::::: Mobil berhasil keluar :::::" << endl
					 << endl;
			cin >> getchar;
			dequeue();
			cout << endl;
			pop();
			cout << endl;
			break;

		case 6:
			system("clear");
			cout << "::::: Data mobil keluar (disewa) :::::" << endl;
			archive_cetakqueue();
			cetak_archive();
			cin >> getchar;
			break;

		case 7:
			exit(0);
			break;
		}
		ulang = true;
	} while (ulang == true);
}

void buat_stack()
{
	typeptr NS;
	NS = NULL;
	awalstack = NS;
	akhirstack = NS;
}
int stack_kosong()
{
	if (awalstack == NULL)
		return (1);
	else
		return (0);
}

void push(isi_data IB)
{
	typeptr NS;
	NS = (typestack *)malloc(sizeof(typestack));
	NS->info = IB;
	if (awalstack == NULL)
		awalstack = NS;
	else
		akhirstack->next = NS;
	akhirstack = NS;
	akhirstack->next = NULL;
}

void pop()
{
	typeptr hapus, bantu;
	if (stack_kosong())
	{
		cout << "Stack kosong !\n";
	}

	else
	{
		bantu = awalstack;
		hapus = akhirstack;
		if (hapus == awalstack)
			awalstack = NULL;
		else
		{
			while (bantu->next->next != NULL)
			{
				bantu = bantu->next;
			}
			akhirstack = bantu;
			akhirstack->next = NULL;
		}
		// cout << hapus;
		push_archive(hapus->info);
		free(hapus);
	}
}

void cetak_stack()
{
	typeptr bantu;
	int i = 1;

	bantu = awalstack;
	while (bantu != NULL)
	{
		cout << endl
				 << "Data mobil ke - " << i << endl;
		cout << "Nama Mobil : " << bantu->info.nama << endl;
		cout << "Nama Plat : " << bantu->info.plat << endl;
		bantu = bantu->next;
		i++;
	}
}

//=================================
//Buat Archive

void buat_archive()
{
	typeptr NS;
	NS = NULL;
	awalarchive = NS;
	akhirarchive = NS;
}

int archive_kosong()
{
	if (awalarchive == NULL)
		return (1);
	else
		return (0);
}

void push_archive(isi_data IB)
{
	typeptr NS;
	NS = (typestack *)malloc(sizeof(typestack));
	NS->info = IB;
	if (awalarchive == NULL)
		awalarchive = NS;
	else
		akhirarchive->next = NS;
	akhirarchive = NS;
	akhirarchive->next = NULL;
}

void pop_archive()
{
	typeptr hapus, bantu;
	int i = 0;
	if (stack_kosong())
	{
		cout << "Stack kosong !\n";
	}
	else
	{
		bantu = awalarchive;
		hapus = akhirarchive;
		if (hapus == awalarchive)
			awalarchive = NULL;
		else
		{
			while (bantu->next->next != NULL)
			{
				bantu = bantu->next;
				i++;
			}
			akhirarchive = bantu;
			akhirarchive->next = NULL;
		}
		push_archive(hapus->info);
		free(hapus);
	}
}

void cetak_archive()
{
	typeptr bantu;
	int i = 1;

	bantu = awalarchive;
	while (bantu != NULL)
	{
		cout << endl
				 << "Data mobil ke - " << i << endl;
		cout << "Nama Mobil : " << bantu->info.nama << endl;
		cout << "Nama Plat : " << bantu->info.plat << endl;
		bantu = bantu->next;
		i++;
	}
}

//=============================

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

void enqueue(data_penyewa IB)
{
	ptrqueue NB;
	NB = (typequeue *)malloc(sizeof(typequeue));
	NB->info_penyewa = IB;
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
		archive_enqueue(hapus->info_penyewa);
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
		cout << "Data ke - " << i << endl;
		cout << "Nama Penyewa : " << bantu->info_penyewa.nama << endl;
		cout << "No KTP : " << bantu->info_penyewa.ktp << endl;
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

void archive_enqueue(data_penyewa IB)
{
	ptrqueue NB;
	NB = (typequeue *)malloc(sizeof(typequeue));
	NB->info_penyewa = IB;
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
		cout << "Nama Penyewa : " << bantu->info_penyewa.nama << endl;
		cout << "No KTP : " << bantu->info_penyewa.ktp << endl;
		bantu = bantu->next;
		i++;
	} while (bantu != NULL);
}
