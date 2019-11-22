#include <iostream>
#include <malloc.h>
#include <iomanip>
#define true 1
#define false 0
using namespace std;
struct typeinfo{
	int nim;
	char nama[50];
	int uts;
	int uas;
	int akhir;
};
typedef struct typenode *typeptr;
struct typenode{typeinfo info;
				typeptr kiri, kanan;
							  };
typeptr akar,p,b;
int  NH;
void buat_ptb();
int ptb_kosong();
void sisipnode();
void cetakatas();
void cetakbawah();
void preorder(typeptr akar);
void inorder(typeptr akar);
void postorder(typeptr akar);
void hapusnode();
void hapus();
int main()
{
	int pilih;
	do
	{
		system("cls");
		cout<< "=========================="<<endl;
		cout<< "|\t MENU \t\t |" << endl;
		cout<< "=========================="<< endl;
		cout<< "1. BUAT PTB \n";
		cout<< "2. INSERT PTB \n";
		cout<< "3. BACA PREORDER \n";
		cout<< "4. BACA INORDER \n";
		cout<< "5. BACA POSTORDER \n";
		cout<< "6. DELETE PTB \n";
		cout<< "7. EXIT" << endl;
		cout<< "PILIH (1-7) : "; cin >> pilih;
		system("cls");
		switch (pilih)
		{
			case 1:
				buat_ptb();
				break;
			case 2:
				sisipnode();
				break;
			case 3:
				cetakatas();
				preorder(akar);
				cetakbawah();
				break;
			case 4:
				cetakatas();
				inorder(akar);
				cetakbawah();
				break;
			case 5:
				cetakatas();
				postorder(akar);
				cetakbawah();
				break;
			case 6:
				hapusnode();
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<< "SALAH INPUT!!!";
		}
		cout<< endl << endl;
		system("pause");
	} while (true);
  return 0;
}

void buat_ptb()
{ typeptr ptb;
  ptb=NULL;
  akar=ptb; }

int ptb_kosong()
{ if(akar==NULL)
	 return(true);
  else
	 return(false); }
	 
void sisipnode()
{ typeptr NB;
	typeinfo IB;
	cout<< "Nama \t: "; cin.ignore(); cin.getline(IB.nama, sizeof(IB.nama));
	cout<< "NIM \t: "; cin >> IB.nim;
	cout<< "UTS \t: "; cin >> IB.uts;
	cout<< "UAS \t: "; cin >> IB.uas;
	IB.akhir = (IB.uts + IB.uas)/2;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  NB->kiri=NULL;
  NB->kanan=NULL;
  if (ptb_kosong())
	 akar=NB;
  else
	 { b=akar;
		p=akar;
		// mencari tempat untuk menyisipkan node
		while(p!=NULL && IB.nim!=p->info.nim)
		  { b=p;
			 if (IB.nim<p->info.nim)
				p=b->kiri;
			 else
				p=b->kanan; }
		if (IB.nim==b->info.nim)
		  cout << "\n\nNode " << IB.nama << " sudah ada !\n\n";
		else
		  { if (IB.nim<b->info.nim)
				b->kiri=NB;
			 else
				b->kanan=NB; }
	 }
}

void cetakatas(){
	cout<< "------------------------------------------------------------------------" << endl;
	cout<< "  |       NIM       |         NAMA         |  UTS  |  UAS  |  AKHIR  |  " << endl;
	cout<< "------------------------------------------------------------------------" << endl;
}
void cetakbawah(){
	cout<< "------------------------------------------------------------------------" << endl;
}
void preorder(typeptr akar)
{ if (akar!=NULL)
	 { cout << "  |  " << setw(13) << akar->info.nim;
		 cout << "  |  " << setw(18) << akar->info.nama;
		 cout << "  |  " << setw(3) << akar->info.uts;
		 cout << "  |  " << setw(3) << akar->info.uas;
		 cout << "  |  " << setw(5) << akar->info.akhir;
		 cout << "  |  " << endl;
		preorder(akar->kiri);
		preorder(akar->kanan); }
}
void inorder(typeptr akar)
{ if (akar!=NULL)
	 { inorder(akar->kiri);
		cout << "  |  " << setw(13) << setiosflags(ios::left) << akar->info.nim;
		 cout << "  |  " << setw(18) << akar->info.nama;
		 cout << "  |  " << setw(3) << akar->info.uts;
		 cout << "  |  " << setw(3) << akar->info.uas;
		 cout << "  |  " << setw(5) << akar->info.akhir;
		 cout << "  |  " << endl;
		inorder(akar->kanan); }
}
void postorder(typeptr akar)
{ if (akar!=NULL)
	 { postorder(akar->kiri);
		postorder(akar->kanan);
		cout << "  |  " << setw(13) << akar->info.nim;
		 cout << "  |  " << setw(18) << akar->info.nama;
		 cout << "  |  " << setw(3) << akar->info.uts;
		 cout << "  |  " << setw(3) << akar->info.uas;
		 cout << "  |  " << setw(5) << akar->info.akhir;
		 cout << "  |  " << endl;}
}
void hapusnode()
{
  if (ptb_kosong())
	  cout << "PTB Kosong !\n\n";
  else
	 { 
		 typeinfo IH;
		 cout<< "Masukkan nim yang akan dihapus : "; cin >> IH.nim;
		 b=akar;
		p=akar;

		// mencari tempat hapus node
		while(p!=NULL && IH.nim!=p->info.nim)
		  { b=p;
			 if (IH.nim<p->info.nim)
				p=b->kiri;
			 else
				p=b->kanan; }
	 }
  hapus();
}
void hapus()
{ typeptr temp;
// Bila PTB terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
  if (p->kiri==NULL && p->kanan==NULL)
	  {
		 if (b==akar && p==akar)
			 akar=NULL;
		 else
			 {
				if (p==b->kiri)
					b->kiri=NULL;
				else
					b->kanan=NULL;
			 }
		free(p);
	  }


// Bila PTB memiliki anak kiri dan anak kanan dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan!=NULL)
	  {
		 temp=p->kiri;
		 b=p;
		 while (temp->kanan != NULL)
			{ b=temp;
			  temp=temp->kanan; }
		 p->info=temp->info;
		 if (b==p)
			 b->kiri = temp->kiri;
		 else
			 b->kanan = temp->kiri;
		 free(temp);
	  }
// Bila PTB memiliki anak kiri saja dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan==NULL)
	  {
		 if (b==p)
			 akar=p->kiri;
		 else
			{ if (p==b->kiri)
				  b->kiri=p->kiri;
			  else
				  b->kanan=p->kiri;
			}
		 free(p);
	  }

// Bila PTB memiliki anak kanan saja dgn banyak anak cabang
  else if (p->kiri==NULL && p->kanan!=NULL)
	  {
		 if (b==p)
			 akar=p->kanan;
		 else
			{ if (p==b->kanan)
				  b->kanan=p->kanan;
			  else
				  b->kiri=p->kanan;
			}
		 free(p);
	  }
}
