#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include "SortingAlgorythms.hh"
using namespace std;
using namespace std::chrono;


enum Order{
  growing=true,
  decending=false
};

struct Statistica{
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

double sorts(int tab[]){
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      
      int *help=CreateTab<int>(Length);
      MergeSort<int>(0,Length-1,tab,help)  ;
      //quicksort(0,Length-1,tab,growing);
      //heapsort(Length,tab);
      //insertionsort(0,Length,tab);
      introspectivesort(0,Length-1,log(Length)*2/M_LN2,tab,growing);
      //check(tab);
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

return time_span.count()*1000;
}

void PrepareForSorts(int tab[],Order order,double percentage){
  double HowMuch=(percentage/100*Length);
  int end=static_cast<int>(HowMuch);
  quicksort(0,end-1,tab,order);
}

int main(){
  Order order;
  order=growing;
  Statistica stats[8];
  double percentage[8]={0,25,50,75,95,99,99.7,100};

  int *tab=CreateTab<int>(Length);
  srand( time( NULL ) );

  for(int k=0;k<8;k++){
    for(int i=0;i<AmountOfTabs;i++){

      for (int j = 0; j < Length; j++){
       tab[j] = rand() %10000 ;
      }
      
      if(k==7){
         order=decending;
      }
      
      PrepareForSorts(tab,order,percentage[k]);
      stats[k].TimeTab[i]=sorts(tab);
      Print(tab,Length);
      check(tab,Length,true);
    }
  }

      deleteTab(tab);
  cout << "Sortowanie intro. Liczba elem:" << Length << endl; 
  
  for(int i=0;i<8;i++){
    cout << percentage[i] << " , " << stats[i].GetAverage() << " , " <<stats[i].GetTheBest() << " , " << stats[i].GetTheWorst();
    cout << endl ;
  }

}