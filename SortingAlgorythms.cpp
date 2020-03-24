#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include "SortingAlgorythms.hh"
using namespace std;
using namespace std::chrono;

/**
 * @brief W tym pliku znajduje sie metody struktury potrzebnej do statystyki 
 * oraz przyklad dzialania programu dla malej liczby danych 
 * 
 */


/**
 * @brief Kolejnosc sortowania
 * 
 */
enum Order{
  growing=true,
  decending=false
};

/**
 * @brief Wybor sortowania
 * 
 */
enum Choose{
  Squick,
  Smerge,
  Sintro
};

double Statistica::GetAverage(){
  double mid=0;
  for(int i=0;i<AmountOfTabs;i++){
    mid+=TimeTab[i];
  }
return (mid/100);
}

double Statistica::GetTheBest(){
  double TheBest=TimeTab[0];
  for(int i=1;i<AmountOfTabs;i++){
    if(TimeTab[i]<TheBest)
    TheBest=TimeTab[i];
  }
return TheBest;
}

double Statistica::GetTheWorst(){
  double TheWorst=TimeTab[0];
  for(int i=1;i<AmountOfTabs;i++){
    if(TimeTab[i]>TheWorst)
    TheWorst=TimeTab[i];
  }
return TheWorst;  
}

/**
 * @brief Sortowanie wraz z obliczaniem czasu sortowania
 * 
 * @param tab - tablica do posortowania
 * @param sorting - sposob sortowania
 * @return double - czas sortowania
 */
double sorts(int tab[],Choose sorting){
      int *help=CreateTab<int>(Length);
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      switch (sorting)
      {
      case 0:
        quicksort(0,Length-1,tab,growing);
        break;
      
      case 1:
        MergeSort<int>(0,Length-1,tab,help)  ;
        break;
      
      case 2:
        introspectivesort(0,Length-1,log(Length)*2/M_LN2,tab);
        break;
      
      default:
        break;
      }
  
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
      deleteTab(help);

return time_span.count()*1000;
}


/**
 * @brief Przygotowanie pod sortowanie - funkcja wspomagajaca testy
 * 
 * @param tab - tablica do przygotowania
 * @param order - kolejnosc uporzadkowania
 * @param percentage - procent danych do posortowania
 */
void PrepareForSorts(int tab[],Order order,double percentage){
  double HowMuch=(percentage/100*Length);
  int end=static_cast<int>(HowMuch);
  quicksort(0,end-1,tab,order);
}



int main(){
  Order order;
  Choose choose[3]={Squick,Smerge,Sintro};
  string name[3]={"szybkie","przez scalanie","introspektywne"};
  order=growing;
  Statistica stats;
  double percentage=0;

  int *tab=CreateTab<int>(Length);
  srand( time( NULL ) );

  for(int choice=0;choice<3;choice++){
    for(int i=0;i<AmountOfTabs;i++){

      for (int j = 0; j < Length; j++){
       tab[j] = rand() %10000 ;
      }

      cout << "Sortowanie "<< name[choice] << " Liczba elementow do posortowania:" << Length << endl <<"Tablica wstepna:     " ;
      PrepareForSorts(tab,order,percentage);
      Print(tab,Length);
      stats.TimeTab[i]=sorts(tab,choose[choice]);
      check(tab,Length,growing);
      cout << "Tablica posortowana: ";
      Print(tab,Length);
      check(tab,Length,true);
    }
  
    cout << "Czas sortowania: " << setw(5)  << stats.GetAverage() ;
    cout << endl ;
  
  } 

deleteTab(tab);

cout << "Projekt wykonal : Jakub Kedzierski 248915" << endl; 
}