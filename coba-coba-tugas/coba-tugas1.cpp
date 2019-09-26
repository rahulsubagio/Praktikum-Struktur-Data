#include <iostream>
#include <malloc.h>

using namespace std;

typedef int typeinfo;             // mengaliaskan integer ke typeinfo
typedef struct typenode *typeptr; // membuat struct pointer typeptr

// membuat struct typenode utk mengelompokkan data
struct typenode
{
  typeinfo info, nim; // info sbg penyimpan awal dan akhir, nim sbg primary key / sbg pembanding menyisipkan data
  char nama[50];      // deklarasi utk input karakter
  typeptr next;       // deklarasi utk menunjuk linked list berikutnya
};

typeptr awal, akhir; // deklarasi awal dan akhir linked list

// fungsi membuat linked list
void buatlist()
{
  awal = (typenode *)malloc(sizeof(typenode));
  awal->info = -1;
  akhir = (typenode *)malloc(sizeof(typenode));
  akhir->info = 123180101;
  awal->next = akhir;
  akhir->next = NULL;
}

// fungsi input linked list
void inputlist()
{
  int n;
  cout << "banyak data : ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    typeptr inputdata, bantu;
    inputdata = (typenode *)malloc(sizeof(typenode));
    cout << "Nama : ";
    cin >> inputdata->nama;
    cout << "Nim  : ";
    cin >> inputdata->nim;
    cout << endl;
    inputdata->info = inputdata->nim;
    inputdata->next = NULL;
    bantu = awal;
    while (bantu->next->info < inputdata->nim)
    {
      bantu = bantu->next;
    }
    inputdata->next = bantu->next;
    bantu->next = inputdata;
  }
}

// fungsi utk menampilkan data
void cetaklist()
{
  typeptr bantu;
  int i = 1;
  bantu = awal->next;
  while (bantu != akhir)
  {
    cout << "MHS " << i << "\nNama : " << bantu->nama << endl;
    cout << "Nim  : " << bantu->nim << endl;
    bantu = bantu->next;
    i++;
  }
  cout << endl;
}

// fungsi utama
int main()
{
  buatlist();
  bool a = false;
  char y;
  do
  {
    inputlist();
    cout << "\ntambah data? (y/n) : ";
    cin >> y;
    cout << endl;

    if (y == 'y' || y == 'Y')
    {
      a = true;
    }
    else
      a = false;

  } while (a == true);

  cout << "\nCetak List\n";
  cetaklist();
}
