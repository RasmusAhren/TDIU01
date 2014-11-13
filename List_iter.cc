#include "List.h"

bool empty(const List orglist)
{
  if(orglist == nullptr)//ITER
    {
       return true;
    }
  else
    {
      return false;
    }
}

bool member(const List orglist, const int val)
{
  cout << "chekcing: " << val << endl;
  List temp = orglist;

  while(!(empty(temp) || temp->data > val))
    {
      if(temp->data == val)
	{
	  cout << "ITER_member() = true" << endl; 
	  return true;
	}
      else
	{
	  temp = temp->next;	  
	}
    }
  cout << "member() = false!" << endl;
  return false;
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
