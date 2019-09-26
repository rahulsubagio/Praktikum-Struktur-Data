#include <iostream>
#include <malloc.h>

using namespace std;

// membuat struct typenode utk info dan pointer next
struct typenode
{
  string info;    // deklarasi info sbg string
  typenode *next; // deklarasi pointer next sbg typenode
};

int main()
{
  string N;                                    // deklarasi utk inputan
  typenode *awal, *bantu;                      // deklarasi pointer awal dan bantu
  awal = (typenode *)malloc(sizeof(typenode)); // menunjuk lokasi dari typenode
  bantu = awal;

  cout << "Masukkan karakter (n = stop) : " << endl;

  // looping utk menginput data
  while (bantu != NULL)
  {
    cin >> N;
    if (N == "n") // jika inputan = n maka program selesai
    {
      bantu->next = NULL;
      bantu = NULL;
    }

    else // jika inputan != n maka program akan mengulang
    {
      bantu->info = N;
      bantu->next = (typenode *)malloc(sizeof(typenode));
      bantu = bantu->next;
    }
  }
  cout << endl
       << "Cetak :" << endl;
  bantu = awal;

  while (bantu != NULL) // perulangan utk menampilkan linked lis
  {
    cout << bantu->info << endl;
    bantu = bantu->next; //
  }
}
