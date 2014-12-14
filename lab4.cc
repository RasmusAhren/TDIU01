#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
using List = struct deltagare *;


struct deltagare
{
  int start{}; 
  string name{}; 
  string surname{}; 
  string club{};
  double result{};
  List next{};
};


bool member(const List orglist, const int val, const double result);
bool empty(const List orglist);
void print(const List orglist);
void clear(List& lista);
void print(vector<deltagare> const & list);
bool inmatning(ifstream& personfil, List& deltagar_lista);
//bool inmatning(ifstream& personfil, List& deltagar_lista);
bool rekmatning(ifstream& personfil, List& deltagar_lista);
bool tid_inmatning(ifstream & resultfil, List& orglist);
bool result_sort(List& orglist, List& currentlist);

int main(int argc, char* argv[])
{
  if(argc !=3)
    {
      cerr << "fel antal filer som kommandoradsargument. (Det ska vara 3 filer)"
	   << endl;
      return 1;
    }
  string personfilnamn{argv[1]};
  //  cerr << personfilnamn << endl;
  List lista{};
  ifstream ifs{personfilnamn};


  inmatning(ifs,lista);
  ifs.close();

  ifs.open(argv[2]);
  tid_inmatning(ifs,lista);  
  //  findresult()


  print(lista);

  clear(lista);

  return 0;
}


/*-------

  void inmatning(const string& personfil, List& deltagar_lista)
  {
  if(deltagar_lista != nullptr)
  {
  cerr << "inmatning: Deltagarlista ej tom" << endl;
  return;
  }

  deltagare temp{};
  
  cerr << " --- inmatning startar: " << endl;

  ifstream ifs{personfil};
  if (!ifs)
  {
  cerr << "Fel i inmatning() " << endl;
  return;
  }


  cin.ignore(9001,'/n');
    
  while(!ifs.eof())
  {
  ifs >> temp->start >> temp->name >> temp->surname;
  get.line(ifs, temp->club);

  List newtemp{new deltagare};
  temp->next = newtemp;
  } 

  ifs.close();
  return;
  }

  -------*/

bool inmatning(ifstream& personfil, List& deltagar_lista)
{
  if(personfil.eof())
    {
      return false;
    }

  personfil.ignore(9001,'\n');

  return rekmatning(personfil,deltagar_lista);
}

bool rekmatning(ifstream& personfil, List& deltagar_lista)
{
  //  cerr << "Rekmatning start: " << endl;
  
  personfil.peek();
  if(personfil.eof())
    {
      return true;
    }

  List temp(new deltagare);
  personfil >> temp->start >> temp->name >> temp->surname;

  getline(personfil, temp->club);
    
  temp->next = deltagar_lista;
  deltagar_lista = temp;

  return (rekmatning(personfil, temp->next));
}

void print(const List orglist)
{
  if(orglist == nullptr)
    {
      return;
    }
  else
    {
      cout << orglist->name << "    " << orglist->result << endl;
      print(orglist->next);
    }
}


void clear(List &lista)
{
  if(lista == nullptr)
    return;
  else if(!(lista->next == nullptr))
    {
      clear(lista->next);
    }
  delete lista;
  lista =  nullptr;
}

bool empty(const List orglist)
{
  if(orglist == nullptr)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool member(const List orglist, const int start, const double result)
{
  if(empty(orglist))
    {
      //      cout << orglist->data << endl;
      //      cerr << "member() = false!" << endl;
      return false;
    }
  else if(orglist->start == start)
    {
      orglist->result = result;
      
      //    cerr << "member() = true" << endl; 
      return true;
    }
  else
    //    cout << "omstart!" << endl;
    return (member(orglist->next,start,result));
}

bool tid_inmatning(ifstream & resultfil, List& orglist)
{
  int tempStart{};
  double tempResult{};


  resultfil.ignore(9001,'\n');

  while(resultfil >> tempStart)
    {
      while(resultfil.peek() != '\n')
	{
	  resultfil >> tempResult;
	  cerr << tempResult;
	}
      cerr << "tid_in skriv" << endl;
  member(orglist, tempStart, tempResult);
    }
  return true;
}

bool result_sort(List& orglist, List& currentlist)
{
  if(empty(orglist))
    return false;
  else if(empty(currentlist->next))
    return true;

  if(currentlist->result > currentlist->next->result)
    {
      cerr << "result_sort i swap-if" << endl;
      List temp{currentlist->next};
      currentlist->next = currentlist->next->next;
      temp->next = currentlist;
      currentlist = temp;
      return result_sort(orglist, orglist);
    }
  else if(currentlist->result == currentlist->next->result && currentlist->name > currentlist->next->name)
    {
      cerr << "result_sort i exakt samma tid else-if " << endl;
      List temp{currentlist->next};
      currentlist->next = currentlist->next->next;
      temp->next = currentlist;
      currentlist = temp;
      return result_sort(orglist, orglist);
    }
  else if(currentlist->result == currentlist->next->result && currentlist->name == currentlist->next->name && currentlist->surname > currentlist->next->surname)
    {
      List temp{currentlist->next};
      currentlist->next = currentlist->next->next;
      temp->next = currentlist;
      currentlist = temp;
      return result_sort(orglist, orglist);
    }
  else
    {
      cerr << "result_sort i swap-else  " << currentlist->result << endl;
      return result_sort(orglist, currentlist->next);
    }


}
