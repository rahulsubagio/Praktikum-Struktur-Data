#include <iostream>
#include <malloc.h>

using namespace std;

typedef char typeinfo;
typedef struct typestack *typeptr;
struct typestack
{
  typeinfo info;
  typeptr next;
};

typeptr stack, stackawal;

void buatstack()
{
  typeptr NS;
  NS = (typestack *)malloc(sizeof(typestack));
  NS = NULL;
  stackawal = NS;
}

void push()
{
  char IB;
  cin >> IB;
  typeptr NS;
  NS = (typestack *)malloc(sizeof(typestack));
  NS->info = IB;
  if (stackawal == NULL)
  {
    stackawal = NS;
  }
  else
  {
    stack->next = NS;
  }
  stack = NS;
  stack->next = NULL;
}

void pop()
{
  typeptr hapus, bantu;
  bantu = stackawal;
  hapus = stack;
  if (hapus == stackawal)
  {
    stackawal = NULL;
  }
  else
  {
    while (bantu->next->next != NULL)
    {
      bantu = bantu->next;
      stack = bantu;
      stack->next = NULL;
    }
  }
  free(hapus);
}

void cetakstack()
{
  typeptr bantu;
  bantu = stackawal;
  while (bantu != NULL)
  {
    cout << " " << bantu->info << endl;
    bantu = bantu->next;
  }
}

int main()
{
  int pilih;
  char y;
  buatstack();
  do
  {
    system("clear");
    cout << "Menu :\n 1. Push\n 2. POP\n 3. Cetak\nPilih : ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
      system("clear");
      push();
      break;
    case 2:
      system("clear");
      pop();
      break;
    case 3:
      system("clear");
      cetakstack();
      cout << endl
           << endl;
      char c;
      cin >> c;
      break;
    }
    y = 'y';
  } while (y == 'y');
}
