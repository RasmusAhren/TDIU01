#include <iostream>
#include "List.h"
using namespace std;

// using List = struct List_Type *;

// // struct List_Type
// // {
// //   int data;
// //   List next;
// // };
// // void insert_first(List & orglist, const int val); // TEMPORÄR LISTBYGGARE "PLAGIAT!"

// // bool insert(List & orglist,const int val);
// // bool remove(List & orglist, const int val);
// // bool empty(const List orglist);
// // bool member(const List orglist, const int val);

// // void print(const List orglist);
// // void clear(List & orglist);

// // int size(const List orglist);




/*--------------------------------------------------------*/

int main()
{
  cout << endl << "   --- Program som leker listlek. ---   " << endl << endl;
  
  List test{}; //new List_Type{}};//{0, nullptr}};
  for(int i{0}; i<147; i+=3)
    {
    insert(test, i);
    }

      //DEBUG
  //FULL LISTA

  print(test);
  cout << "SIZE IS NOW: "<< size(test) << endl;
  insert(test, 6);
  //REMOVE

  remove(test,9);

  //EFTER REMOVE

  print(test);
  cout << "SIZE IS NOW: "<< size(test) << endl;

  cout << "CLEAR LIST" << endl;

  //EFTER CLEAR
  clear(test);
  print(test);
  cout << "SIZE IS NOW: "<< size(test) << endl;

      //SLUTEBUG


  cout << endl;
  return 0;
}
/*---------------------------------------------------------*/





/*------------------------

bool empty(const List orglist)
{
  if(orglist == nullptr)
    {
      // cout << "empty() = TRUE " << endl;
      return true;
    }
  else
    {
      // cout << "Data i empty(): " << orglist->data << endl;
      // cout << "empty() = FALSE" << endl;
      return false;
    }
}

bool member(const List orglist, const int val)
{
  cout << "chekcing: " << val << endl;
  if(empty(orglist) || orglist->data > val)
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
  //  cout << endl << "REMOVE START!" << endl;
  
  if(empty(orglist))
    {
      //      cout << "remove() = FALSE!" << endl;
      return false;
    }
  else if(orglist->data == val)
    {
      //      cout << "remove() = TRUE!" << endl;

      List temp{orglist};

      orglist = orglist->next;
      delete temp;

      return true;
    }
  else
    return remove(orglist->next, val);
}

void insert_first(List & orglist, const int val) //PLAGIAT TEST
{
  if(empty(orglist))
    {
      List temp{new List_Type};
      temp->data = val;
      temp->next = nullptr;
      orglist = temp;
    }
  else
    {
      List temp{new List_Type};
      temp->data = val;
      temp->next = orglist;
      orglist = temp;
    }
}

void print(const List orglist)
{
  if(empty(orglist))
    {
      cout << "PRINT SLUT" << endl;
      return;
    }
  else
    {
      cout << orglist->data << ", " << flush;
      print(orglist->next);
    }
}

int size(const List orglist)
{
  if(empty(orglist))
    {
      return 0;
    }
  else
    {
      return(1+size(orglist->next));
    }
}

void clear(List & orglist)
{
  if(empty(orglist))
    return;
  else if(!empty(orglist->next))
    {
      clear(orglist->next);
    }
  delete orglist;
  orglist =  nullptr;
}

bool insert(List & orglist,const int val)
{
  if(empty(orglist) || orglist->data > val)
    {
      List temp{new List_Type};
      temp->data = val;
      temp->next = orglist;
      orglist = temp;
      return true;
    }
  else if(val == orglist->data)
    {
      return false;
    }
  else
    {
      return insert(orglist->next, val);
    }
}
--------------------------------*/
