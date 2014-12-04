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
  string result{};
  List next{};
};


void print(const List orglist);
void clear(List& lista);
void print(vector<deltagare> const & list);
bool inmatning(ifstream& personfil, List& deltagar_lista);
//bool inmatning(ifstream& personfil, List& deltagar_lista);
bool rekmatning(ifstream& personfil, List& deltagar_lista);

int main(int argc, char* argv[])
{
  if(argc !=2)
    {
      cerr << "fel antal filer som kommandoradsargument. (Det ska vara 3 filer)"
	   << endl;
      return 1;
    }
  string personfilnamn{argv[1]};
  cerr << argc << endl;
  cerr << personfilnamn << endl;
  List lista{};
  ifstream ifs{personfilnamn};


  inmatning(ifs,lista);
  ifs.close();

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
      cout << orglist->name << ", " << flush << endl;
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
