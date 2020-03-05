#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <algorithm>
#include "SortingAlgorythms.hh"
using namespace std;
using namespace std::chrono;
const char* mainbody="tabs.csv";
const int AmountOfTabs=100;


/*Sorts algorythms for introspective sort use*/////////////////////////////////////////
void heapify(int n,int id,int tab[]){
  int idhelp=id,left=2*id+1,right=2*id+2;

  if(left<n && tab[left]>tab[idhelp]){
    idhelp=left;
  }else idhelp=id;
  
  if(right<n && tab[right]>tab[idhelp])
    idhelp=right;

  if(idhelp !=id){
    swap(tab[id],tab[idhelp]);
    heapify(n,idhelp,tab);
  }

}

void heapsort(int n,int tab[]) 
{ 
    for (int i=n/2-1;i>=0;i--) 
        heapify(n,i,tab); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(tab[0], tab[i]); 
        heapify(i,0,tab); 
    } 
} 

void insertionsort(int id0,int id1,int tab[]){
  int help=0,i;
  
  for(int j=id1-2;j>=id0;j--)
  {
    help = tab[j];
    i = j + 1;
    while((i < id1) && (help > tab[i]))
    {
      tab[i - 1] = tab[i];
      i++;
    }
    tab[i - 1] = help;
  }

}
//////////////////////////////////////////////////

void introspectivesort(int id0,int id1,int maxdepth,int tab[]){
  int j;
  if((id1-id0)<=0) return;

  if(id1-id0>16){
    
    if(maxdepth==0){
    heapsort((id1-id0+1),tab+id0);
    }
    
    maxdepth--;
    j=FindingPivot(id0,id1,tab);
    introspectivesort(id0,j-1,maxdepth,tab);
    introspectivesort(j+1,id1,maxdepth,tab);
   
  }else{
  insertionsort(id0,id1+1,tab); // za czesto sie to wykonuje
  }
}

void Print(int tab[Length]){
        for(int j=0;j<Length;j++){
          cout << tab[j] << " " ;
        }
        cout << endl;
}

double sorts(int tab[]){
      high_resolution_clock::time_point t1 = high_resolution_clock::now();
      //MergeSort<int>(0,Length-1,tab)  ;
      quicksort(0,Length-1,tab);
      //sort(tab,tab+Length,greater<int>());
      //heapsort(Length,tab);
      //insertionsort(0,Length,tab);
      //introspectivesort(0,Length-1,log(Length)*2/M_LN2,tab);
      check(tab);
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
      duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
return time_span.count();
}

int main(){
  
    int *tab=CreateTab(Length);
    srand( time( NULL ) );
    double k;  
    
    for(int i=0;i<1;i++){

      for (int j = 0; j < Length; j++){
       tab[j] = rand() %10000 ;
      }

      k=sorts(tab);
      //Print(tab);
    }

      deleteTab(tab);  
  

  cout << endl << "Czas sortowania dla 100 tablic o rozmiarze " << Length << " :" << k ;
  cout << endl;

}