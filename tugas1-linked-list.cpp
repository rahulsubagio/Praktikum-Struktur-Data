#include <iostream>
#include <malloc.h>

using namespace std;

typedef int typeinfo;
typedef struct typenode *typeptr;

struct typenode
{
  typeinfo info, nim;
  char nama[50];
  typeptr next;
};

typeptr awal, akhir;

void buatlist()
{
  awal = (typenode *)malloc(sizeof(typenode));
  awal->info = 123180000;
  akhir = (typenode *)malloc(sizeof(typenode));
  akhir->info = 123180101;
  awal->next = akhir;
  akhir->next = NULL;
}

void inputlist()
{
  typeptr inputdata, bantu;
  inputdata = (typenode *)malloc(sizeof(typenode));
  cout << "Nama : ";
  cin >> inputdata->nama;
  cout << "Nim  : ";
  cin >> inputdata->nim;
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

int main()
{
  buatlist();
  int n;
  cout << "banyak data : ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    inputlist();
  }
  cout << "\nCetak List\n";
  cetaklist();
}
