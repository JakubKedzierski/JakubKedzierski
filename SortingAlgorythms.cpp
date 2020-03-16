#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <algorithm>
#include "SortingAlgorythms.hh"
using namespace std;
using namespace std::chrono;
const int AmountOfTabs=100;

enum Order{
  growing=true,
  decending=false
};

class Statistica{
  public:
  double TimeTab[AmountOfTabs];
  double GetAverage();
  double GetTheWorst();
  double GetTheBest();
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

double sorts(int tab[],Order order,double percentage){
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      double HowMuch=(percentage/100*Length);
      int end=static_cast<int>(HowMuch);
      //MergeSort<int>(0,end-1,tab)  ;
      quicksort(0,end-1,tab,order);
      //heapsort(end,tab);
      //insertionsort(0,end,tab);
      //introspectivesort(0,end-1,log(end)*2/M_LN2,tab,order);
      //check(tab);
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
return time_span.count();
}

int main(){
  Order order;
  order=growing;
  Statistica stats;

  int *tab=CreateTab<int>(Length);
  srand( time( NULL ) );
    
    for(int i=0;i<100;i++){

      for (int j = 0; j < Length; j++){
       tab[j] = rand() %10000 ;
      }

      stats.TimeTab[i]=sorts(tab,order,100);
    }

      deleteTab(tab);
  
  cout << endl << "Sredni czas sortowania tablic o rozmiarze " << Length << " :" << stats.GetAverage() ;
  cout << endl;
  cout << "Najlepszy przypadek: " << stats.GetTheBest() << endl; 
  cout << "Najgorszy przypadek: " << stats.GetTheWorst() << endl;

}