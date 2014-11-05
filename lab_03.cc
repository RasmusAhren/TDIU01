#include <iostream>
using namespace std;
using List = struct List_Type *;

struct List_Type
{
  int data;
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
  empty(test);
  member(test,12);
  /*  cout << test->next << endl;
  delete test;

  int* testa{new int{16}};
  cout << *testa;
  delete testa;
*/
  delete test;
  return 0;
}


bool empty(const List orglist)
{
  if(orglist == nullptr)
    {
      //      cout << "hazza!" << endl;
      return true;
    }
  else
    {
      //      cout << "aaww" << endl;
      return false;
    }
}

bool member(const List orglist, const int val)
{
  if(empty(orglist) || orglist->data > val)
    {
      cout << "false!" << endl;
      return false;
    }
  else if(orglist->data == val)
    {
      cout << "true" << endl; 
      return true;
    }
  else
    cout << "omstart!" << endl;
    return (member(orglist->next,val));
}
