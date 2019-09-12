#include <iostream>

using namespace std;

int main()
{
	typedef	struct { //struct untuk pelanggan
		string nama; 
		int umur;
	}pelanggan;
	
	typedef struct { //struct untuk barang
		int kode_brg;
		string nama_brg;
		int harga;
	}belanja;
	#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Banyak : ";cin>>n;
	
	typedef struct
	{
		char nama_matkul[100],kode[10],dosen[100];
	} data_matkul;
	
	typedef	struct //tipe data mahasiswa
	{
		char nama[100],kelas;
		int nim[9];
		data_matkul matkul[10];
	} data_mhs;
	data_mhs mhs[100];
	
	for (int i = 0; i < n; i++) //input data mhs
	{
		cout<<"Input Data Mahasiswa "<<i+1<<endl;
		cout<<"Nama		: ";cin.ignore();cin.getline(mhs[i].nama,100);
		cout<<"Nim		: ";cin>>mhs[i].nim[i];
		cout<<"Kelas		: ";cin>>mhs[i].kelas;
		cout<<"Kode Matkul	: ";cin>>mhs[i].matkul[i].kode[i];
		cout<<"Matkul		: ";cin.getline(mhs[i].matkul[i].nama_matkul,100);
		cout<<"Dosen		: ";cin.ignore();cin.getline(mhs[i].matkul[i].dosen,100);
	}
	cout<<endl;
	for (int i = 0; i < n; i++) //output data mhs
	{
		cout<<"Data Mahasiswa "<<i+1<<endl;
		cout<<"Nama	: "<<mhs[i].nama<<endl;
		cout<<"Nim	: "<<mhs[i].nim<<endl;
		cout<<"Kelas	: "<<mhs[i].kelas<<endl;
		cout<<"Kode Matkul	: "<<mhs[i].matkul[i].kode[i]<<endl;
		cout<<"Matkul		: "<<mhs[i].matkul[i].nama_matkul<<endl;
		cout<<"Dosen		: "<<mhs[i].matkul[i].dosen<<endl;
	}
}

	pelanggan pembeli[100];
	belanja brg[100];
	int pilih, jumlah1, jumlah2[100];
	bool y;
	do
	{
		system("cls");
		cout<<"STRUCT\n1. Input Struct\n2. Output Struct\n3. Exit\nPilih : ";
		cin>>pilih;
		switch (pilih)
		{
			case 1:
				cout<<"\nMasukkan banyak pelanggan : ";cin>>jumlah1;
				for (int i = 0; i < jumlah1; i++)
				{
					cout<<"\nPelanggan ke "<<i+1<<" :"<<endl;
					cout<<"\tNama	: "; cin>>pembeli[i].nama;
					cout<<"\tUmur	: "; cin>>pembeli[i].umur;
					cout<<"\tJumlah barang belanjaan : ";cin>>jumlah2[i];
					for (int j = 0; j < jumlah2[i]; j++)
					{
						cout<<"\t\tBarang ke "<<j+1<<" :"<<endl;
						cout<<"\t\t\tKode Barang	: "; cin>>brg[i].kode_brg;
						cout<<"\t\t\tNama Barang	: "; cin>>brg[i].nama_brg;
						cout<<"\t\t\tHarga Barang	: "; cin>>brg[i].harga;
					}
				}
				y=true;
				break;
			case 2:
				cout<<"OUTPUT DATA BELANJA\n\n";
				for (int i = 0; i < jumlah1; i++)
				{
					cout<<"\nPelanggan ke "<<i+1<<" :"<<endl;
					cout<<"\tNama	: "<<pembeli[i].nama<<endl;
					cout<<"\tUmur	: "<<pembeli[i].umur<<endl;
					cout<<"\tJumlah barang belanjaan : "<<jumlah2[i]<<endl;
					for (int j = 0; j < jumlah2[i]; j++)
					{
						cout<<"\t\tBarang ke "<<j+1<<" :"<<endl;
						cout<<"\t\t\tKode Barang	: "<<brg[i].kode_brg<<endl;
						cout<<"\t\t\tNama Barang	: "<<brg[i].nama_brg<<endl;
						cout<<"\t\t\tHarga Barang	: "<<brg[i].harga<<endl;
					}
				}
				system("pause");
				y=true;
				break;
			case 3:
				exit(0);
				break;
		}
		
	} while (y==true);
	
}
