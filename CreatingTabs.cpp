#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const char* mainbody="tabs.csv";
const int AmountOfTabs=100;


int main(int argc, char *argv[]){  
 if(argc<2)
  {cout << "Wywolanie ./CreatingTabs [rozmiar tablicy]" << endl;return 0;}  
  int Length=atoi(argv[1]);

  srand( time( NULL ) );
  ofstream  filestream;
    
  filestream.open(mainbody, ios::out | ios::trunc);

    if (!filestream.is_open())  {
      cerr << ":(  Operacja otwarcia do zapisu \"" << mainbody << "\"" << endl
	    << ":(  nie powiodla sie." << endl;
      return 1;
    }
    
    for(int j=0;j<AmountOfTabs;j++){
    
      for(int i=0;i<Length;i++){
        filestream << rand() %1000 << ",";
      }

    filestream << endl ;
    }

    filestream.close();

}
