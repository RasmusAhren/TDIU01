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
};

void print(vector<deltagare> const & list);
void inmatning(const string& personfil, List& deltagar_lista);

int main(int argc, char* argv[])
{
  if(argc !=2)
    {
      cerr << "fel antal filer som kommandoradsargument. (Det ska vara 3 filer)"
	   << endl;
      return 1;
    }
  string personfil{argv[1]};
  cerr << argc << endl;
  cerr << personfil << endl;
  List lista{};


  inmatning(personfil,lista);


  return 0;
}

void inmatning(const string& personfil, List& deltagar_lista)
{
  
  cerr << " --- inmatning startar: " << endl;

  ifstream ifs{personfil};
  if (!ifs)
    {
      cerr << "Fel i inmatning() " << endl;
    }

  // skräp forsats bara för .. jag vet inte.
  for(int tic{};tic < 1; ++tic)
    {
      cout << ifs << endl;
    }


  ifs.close();
  return;
}



void print(vector<deltagare> const & list)
{
  for(int i{}; i < list.size(); ++i)
    {
      cout << endl << list.at(i).start << ' ' << list.at(i).name << ' ' << list.at(i).surname << ' ' << list.at(i).club;
    }

  cout << endl;

}
