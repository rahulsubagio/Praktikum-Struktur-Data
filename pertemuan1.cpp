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
