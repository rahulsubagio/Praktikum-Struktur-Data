#include <iostream>
#include <malloc.h>
#include <iomanip>

using namespace std;

struct typeinfo
{
  int nim, uts, uas, akhir;
  char nama[50];
};

typedef struct typenode *typeptr;

struct typenode
{
  typeinfo info;
  typeptr kiri, kanan;
};

typeinfo data[100];
typeptr akar, p, b, awalstack, akhirstack;

int NH;
void buat_ptb();
int ptb_kosong();
void sisipnode(typeinfo IB);
void cetakatas();
void cetakbawah();
void preorder(typeptr akar);
void inorder(typeptr akar);
void postorder(typeptr akar);
void hapusnode();
void hapus();

// archive stack
void buat_stack();
int stack_kosong();
void push(typeinfo IB);
void cetak_stack();

int main()
{
  int pilih;
  char getchar;

  buat_ptb();
  buat_stack();

  do
  {
    system("clear");
    cout << "::::: Menu :::::" << endl
         << endl;
    cout << " 1. Input Data Mahasiswa" << endl;
    cout << " 2. Tampilkan Data" << endl;
    cout << " 3. Hapus Data" << endl;
    cout << " 4. Archive" << endl;
    cout << " 5. Exit" << endl;
    cout << endl
         << "Pilih : ";
    cin >> pilih;
    system("clear");
    switch (pilih)
    {
    case 1:
      int jum_mhs;
      cout << "Input Data Mahasiswa" << endl
           << endl;
      cout << "Masukkan banyak mahasiswa : ";
      cin >> jum_mhs;
      for (int i = 0; i < jum_mhs; i++)
      {
        cout << endl;
        cout << "Input - " << i + 1 << endl;
        cout << "Nama \t: ";
        cin.ignore();
        cin.getline(data[i].nama, sizeof(data[i].nama));
        cout << "NIM \t: ";
        cin >> data[i].nim;
        cout << "UTS \t: ";
        cin >> data[i].uts;
        cout << "UAS \t: ";
        cin >> data[i].uas;
        data[i].akhir = (data[i].uts + data[i].uas) / 2;
        sisipnode(data[i]);
      }
      break;
    case 2:
      cout << "::::::: Preorder :::::::\n";
      cetakatas();
      preorder(akar);
      cetakbawah();
      cout << "\n\n::::::: Inorder :::::::\n";
      cetakatas();
      inorder(akar);
      cetakbawah();
      cout << "\n\n::::::: Postorder :::::::\n";
      cetakatas();
      postorder(akar);
      cetakbawah();
      cout << endl
           << "kembali? : ";
      cin >> getchar;
      break;
    case 3:
      hapusnode();
      break;
    case 4:
      cout << "::::::: Archive :::::::\n\n";
      cetak_stack();
      cout << endl
           << "kembali? : ";
      cin >> getchar;
      break;
    case 5:
      exit(0);
      break;
    default:
      cout << "SALAH INPUT!!!";
    }
    cout << endl
         << endl;
  } while (true);
  return 0;
}

void buat_ptb()
{
  typeptr ptb;
  ptb = NULL;
  akar = ptb;
}

int ptb_kosong()
{
  if (akar == NULL)
    return (true);
  else
    return (false);
}

void sisipnode(typeinfo IB)
{
  typeptr NB;

  NB = (typenode *)malloc(sizeof(typenode));
  NB->info = IB;
  NB->kiri = NULL;
  NB->kanan = NULL;
  if (ptb_kosong())
    akar = NB;
  else
  {
    b = akar;
    p = akar;
    // mencari tempat untuk menyisipkan node
    while (p != NULL && IB.nim != p->info.nim)
    {
      b = p;
      if (IB.nim < p->info.nim)
        p = b->kiri;
      else
        p = b->kanan;
    }
    if (IB.nim == b->info.nim)
      cout << "\n\nNode " << IB.nama << " sudah ada !\n\n";
    else
    {
      if (IB.nim < b->info.nim)
        b->kiri = NB;
      else
        b->kanan = NB;
    }
  }
}

void cetakatas()
{
  cout << "------------------------------------------------------------------------" << endl;
  cout << "  |       NIM       |         NAMA         |  UTS  |  UAS  |  AKHIR  |  " << endl;
  cout << "------------------------------------------------------------------------" << endl;
}

void cetakbawah()
{
  cout << "------------------------------------------------------------------------" << endl;
}

void preorder(typeptr akar)
{
  if (akar != NULL)
  {
    cout << "  |  " << setw(13) << akar->info.nim;
    cout << "  |  " << setw(18) << akar->info.nama;
    cout << "  |  " << setw(3) << akar->info.uts;
    cout << "  |  " << setw(3) << akar->info.uas;
    cout << "  |  " << setw(5) << akar->info.akhir;
    cout << "  |  " << endl;
    preorder(akar->kiri);
    preorder(akar->kanan);
  }
}

void inorder(typeptr akar)
{
  if (akar != NULL)
  {
    inorder(akar->kiri);
    cout << "  |  " << setw(13) << setiosflags(ios::left) << akar->info.nim;
    cout << "  |  " << setw(18) << akar->info.nama;
    cout << "  |  " << setw(3) << akar->info.uts;
    cout << "  |  " << setw(3) << akar->info.uas;
    cout << "  |  " << setw(5) << akar->info.akhir;
    cout << "  |  " << endl;
    inorder(akar->kanan);
  }
}

void postorder(typeptr akar)
{
  if (akar != NULL)
  {
    postorder(akar->kiri);
    postorder(akar->kanan);
    cout << "  |  " << setw(13) << akar->info.nim;
    cout << "  |  " << setw(18) << akar->info.nama;
    cout << "  |  " << setw(3) << akar->info.uts;
    cout << "  |  " << setw(3) << akar->info.uas;
    cout << "  |  " << setw(5) << akar->info.akhir;
    cout << "  |  " << endl;
  }
}

void hapusnode()
{
  if (ptb_kosong())
    cout << "PTB Kosong !\n\n";
  else
  {
    typeinfo IH;
    cout << "Masukkan nim yang akan dihapus : ";
    cin >> IH.nim;
    b = akar;
    p = akar;

    // mencari tempat hapus node
    while (p != NULL && IH.nim != p->info.nim)
    {
      b = p;
      if (IH.nim < p->info.nim)
        p = b->kiri;
      else
        p = b->kanan;
    }
  }
  hapus();
}

void hapus()
{
  typeptr temp;
  // Bila PTB terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
  if (p->kiri == NULL && p->kanan == NULL)
  {
    if (b == akar && p == akar)
      akar = NULL;
    else
    {
      if (p == b->kiri)
        b->kiri = NULL;
      else
        b->kanan = NULL;
    }
    push(p->info);
    free(p);
  }

  // Bila PTB memiliki anak kiri dan anak kanan dgn banyak anak cabang
  else if (p->kiri != NULL && p->kanan != NULL)
  {
    temp = p->kiri;
    b = p;
    while (temp->kanan != NULL)
    {
      b = temp;
      temp = temp->kanan;
    }
    p->info = temp->info;
    if (b == p)
      b->kiri = temp->kiri;
    else
      b->kanan = temp->kiri;
    push(temp->info);
    free(temp);
  }

  // Bila PTB memiliki anak kiri saja dgn banyak anak cabang
  else if (p->kiri != NULL && p->kanan == NULL)
  {
    if (b == p)
      akar = p->kiri;
    else
    {
      if (p == b->kiri)
        b->kiri = p->kiri;
      else
        b->kanan = p->kiri;
    }
    push(p->info);
    free(p);
  }

  // Bila PTB memiliki anak kanan saja dgn banyak anak cabang
  else if (p->kiri == NULL && p->kanan != NULL)
  {
    if (b == p)
      akar = p->kanan;
    else
    {
      if (p == b->kanan)
        b->kanan = p->kanan;
      else
        b->kiri = p->kanan;
    }
    push(p->info);
    free(p);
  }
}

// Archive
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
    return (true);
  else
    return (false);
}

void push(typeinfo IB)
{
  typeptr NS;
  NS = (typenode *)malloc(sizeof(typenode));
  NS->info = IB;
  if (awalstack == NULL)
    awalstack = NS;
  else
    akhirstack->kanan = NS;
  akhirstack = NS;
  akhirstack->kanan = NULL;
}

void cetak_stack()
{
  typeptr bantu;
  int i = 1;

  bantu = awalstack;
  while (bantu != NULL)
  {
    cout << "Data Archive ke - " << i << endl;
    cout << "Nim \t:" << bantu->info.nim << endl;
    cout << "Nama \t:" << bantu->info.nama << endl;
    cout << "UTS \t:" << bantu->info.uts << endl;
    cout << "UAS \t:" << bantu->info.uas << endl;
    cout << "Akhir \t:" << bantu->info.akhir << endl;
    cout << endl;
    bantu = bantu->kanan;
    i++;
  }
}