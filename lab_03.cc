#include <iostream>
using namespace std;
using List = struct List_Type *;

struct List_Type
{
  int val;
  List next;
};

bool insert(List & orglist,const int val);
bool remove(List & orglist, const int val);
bool empty(const List orglist);
bool member(const List orglist, const int val);

void print(const List orglist);
void clear(List & orglist);

int size(const List orglist);


int main()
{

  List test{new List_Type{15, nullptr}};
  cout << test->next << endl;
  delete test;

  int* testa{new int{16}};
  cout << *testa;
  delete testa;

  return 0;
}