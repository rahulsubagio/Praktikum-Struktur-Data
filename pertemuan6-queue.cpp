#include <iostream>
#include <malloc.h>

#define max 50
#define True 1
#define False 0

using namespace std;

struct typequeue
{
  int belakang;
  int elemen[max];
} queue;

void buatqueue()
{
  queue.belakang = 0;
}

int queuekosong()
{
  if (queue.belakang == 0)
    return (True);
  else
    return (False);
}

int queuepenuh()
{
  if (queue.belakang == max)
    return (True);
  else
    return (False);
}

void enqueue()
{
  int IB;
  cout << "Masukkan nilai : ";
  cin >> IB;
  if (queuepenuh())
    cout << "queue overflow\n";
  else
  {
    queue.belakang++;
    queue.elemen[queue.belakang] = IB;
  }
}

void dequeue()
{
  int ID, i;
  if (queuekosong())
    cout << "queue underflow\n";
  else

  {
    ID = queue.elemen[1];
    for (i = 1; i < queue.belakang; i++)
      queue.elemen[i] = queue.elemen[i + 1];
    queue.belakang--;
  }
}

void cetakqueue()
{
  int i = 1;
  while (i <= queue.belakang)
  {
    cout << " " << queue.elemen[i];
    i++;
  }
}

int main()
{
  int pilih;
  char y;
  buatqueue();

  do
  {
    system("clear");
    cout << "Menu :\n  1. Masuk Antrian\n  2. Ambil Antrian\n  3. Cetak Antrian\n  4.Exit\nPilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
      system("clear");
      enqueue();
      y = 'y';
      break;
    case 2:
      system("clear");
      dequeue();
      cout << "\n\nKemabli Kemenu ? : ";
      cin >> y;
      break;
    case 3:
      system("clear");
      cetakqueue();
      cout << "\n\nKemabli Kemenu ? : ";
      cin >> y;
      break;
    case 4:
      exit(0);
    default:
      break;
    }
  } while (y == 'y');
}
