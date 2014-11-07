#include <iostream>
using namespace std;
using List = struct List_Type *;

struct List_Type
{
  int data;
  List next;
};
void insert_first(List & orglist, const int val); // TEMPORÄR LISTBYGGARE "PLAGIAT!"

bool insert(List & orglist,const int val);
bool remove(List & orglist, const int val);
bool empty(const List orglist);
bool member(const List orglist, const int val);

void print(const List orglist);
void clear(List & orglist);

int size(const List orglist);




/*---------------------------------------------------------*/
int main()
{
  List test{new List_Type{0, nullptr}};
  for(int i{1}; i<15; i+=3)
    {
    insert_first(test, i);
    }

  remove(test,7);



  //  delete test;
  return 0;
}
/*---------------------------------------------------------*/






bool empty(const List orglist)
{
  if(orglist == nullptr)
    {
      cout << "empty() = TRUE " << endl;
      return true;
    }
  else
    {
      cout << "Data i empty(): " << orglist->data << endl;
      cout << "empty() = FALSE" << endl;
      return false;
    }
}

bool member(const List orglist, const int val)
{
  cout << "chekcing: " << val << endl;
  if(empty(orglist))// || orglist->data > val)
    {
      cout << orglist->data << endl;
      cout << "member() = false!" << endl;
      return false;
    }
  else if(orglist->data == val)
    {
      cout << "member() = true" << endl; 
      return true;
    }
  else
    cout << "omstart!" << endl;
    return (member(orglist->next,val));
}

bool remove(List & orglist, const int val)
{
  if(empty(orglist))
    {
      cout << "remove() = FALSE!" << endl;
      return false;
    }
  else if(orglist->data == val)
    {
      cout << "remove() = TRUE!" << endl;

      List temp{orglist}

      delete orglist;

      return true;
    }
}

void insert_first(List & orglist, const int val) //PLAGIAT TEST
{
  cout << "Insert First med Val = " << val << endl;
  if(empty(orglist))
    {
      List temp{new List_Type};
      temp->data = val;
      temp->next = nullptr;
      orglist = temp;
    }
  else
    {

      cout << "insert.org: " << orglist << endl;

      List temp{new List_Type};
      temp->data = val;
      temp->next = orglist;
      orglist = temp;
      cout << "insert.temp: " << temp << endl;
    }
}
