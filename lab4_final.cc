#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
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

bool operator>(const deltagare& currentlist ,const deltagare& next)
{
  return currentlist.result > next.result
    || (currentlist.result == next.result && currentlist.name > next.name)
    || (currentlist.result == next.result && currentlist.name == next.name && currentlist.surname > next.surname);
}


bool insert_result(const List orglist, const int val, const double result);
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
  if(!ifs)
    {
      cerr << "Fel vid öppning av " << argv[2] << endl;
    }
  tid_inmatning(ifs,lista);

  ofs << left << setw(7) << "Plats" << setw(11) << "Sluttid" << setw(15) << "Förnamn" << setw(14) << "Efternamn" << setw(15) << "Klubb" << endl;

  // print(lista,cout);
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
  personfil >> temp->start >> temp->name >> temp->surname >> ws;
  getline(personfil, temp->club);
  temp->next = deltagar_lista;
  deltagar_lista = temp;
  return (rekmatning(personfil, temp->next));
}
void print(const List orglist, ostream & f, int ticker)
{
  if(orglist != nullptr)
    {
      f << left << setw(7) << ticker << setw(11) << orglist->result << setw(15) << orglist->name << setw(14) << orglist->surname << setw(14) << orglist->club << endl;
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
  lista = nullptr;
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
bool insert_result(const List orglist, const int start, const double result)
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
    return (insert_result(orglist->next,start,result));
}


bool tid_inmatning(ifstream & resultfil, List& orglist)
{
  int tempStart{};
  double tempResult{};
  string str{};
  resultfil.ignore(9001,'\n');
  

  while(getline(resultfil,str) )
    {
      stringstream ss{str};
      ss >> tempStart;
      while(ss >> tempResult)
	{
	  
	}
      insert_result(orglist, tempStart, tempResult);
    }
  return true;
}



bool result_sort(List& orglist, List& currentlist)
{
  if(empty(orglist))
    return false;
  else if(empty(currentlist->next))
    return true;
  cerr << "i result-sort" << endl;
  if ( (*currentlist) > (*currentlist->next))
    {
      cerr << "i if sats" << endl;
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
