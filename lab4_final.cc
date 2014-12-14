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
void print(const List orglist, ostream & f=std::cout, int ticker=1);
void clear(List& lista);
bool inmatning(ifstream& personfil, List& deltagar_lista);
bool rekmatning(ifstream& personfil, List& deltagar_lista);
bool tid_inmatning(ifstream & resultfil, List& orglist);
bool result_sort(List& orglist, List& currentlist);


int main(int argc, char* argv[])
{
  if(argc !=4)
    {
            cerr << "fel antal filer som kommandoradsargument. (Det ska vara 3 filer)"
	   << endl;
      return 1;
    }
  string personfilnamn{argv[1]};
  List lista{};
  ifstream ifs{personfilnamn};
  if(!ifs)
    {
      cerr << "Fel vid öppning av " << personfilnamn << endl;
      return 1;
    }
  ofstream ofs{argv[3]};
  if(!ofs)
    {
      cerr << "Fel vid öppning av " << argv[3] << endl;
    }

  inmatning(ifs,lista);
  ifs.close();

  ifs.open(argv[2]);
  tid_inmatning(ifs,lista);

  ofs << left << setw(7) << "Plats" << setw(11) << "Sluttid" << setw(15) << "Förnamn" << setw(14) << "Efternamn" << setw(15) << "Klubb" << endl;
  //  print(lista,cout);
  result_sort(lista,lista);
  print(lista,ofs);
  ofs.close();
  clear(lista);

  return 0;
}


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

void print(const List orglist, ostream & f, int ticker)
{
  if(orglist == nullptr)
    {
      return;
    }
  else
    {
      f << left << setw(7) << ticker << setw(11) << orglist->result << setw(14) << orglist->name << setw(-1) << orglist->surname << setw(14) << orglist->club << endl;
      print(orglist->next,f,(ticker+1));
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
      return false;
    }
  else if(orglist->start == start)
    {
      orglist->result = result;
       return true;
    }
  else
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
	}
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
      List temp{currentlist->next};
      currentlist->next = currentlist->next->next;
      temp->next = currentlist;
      currentlist = temp;
      return result_sort(orglist, orglist);
    }
  else if(currentlist->result == currentlist->next->result && currentlist->name > currentlist->next->name)
    {
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
      return result_sort(orglist, currentlist->next);
    }


}
