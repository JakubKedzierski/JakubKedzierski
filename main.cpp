#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "SortingAlgorythms.hh"
using namespace std;
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

void insertionsort(int id1,int tab[]){
  int help=0,i=0;
  for(int j=1;j<id1;j++){
    help=tab[j];
    
    for(i=j-1;j>=0 && tab[i]>help; i-- )
      tab[i+1]=tab[i];

    tab[i+1]=help;
  }

}
//////////////////////////////////////////////////

void introspectivesort(int id0,int id1,int maxdepth,int tab[]){
  int halfscore=tab[(id0+id1)/2],j=id0;
  if((id1-id0)<16){
    insertionsort(id1+1,tab);
  }else if(maxdepth==0){
    heapsort(id1+1,tab);
  }else{
  //partition
    tab[(id0+id1)/2]=tab[id1];
    for(int i=id0;i<id1;i++){  
      if(tab[i]<halfscore){
        swap(tab[i],tab[j]);
        j++;
      }
    }
    tab[id1]=tab[j];
    tab[j]=halfscore;

    introspectivesort(id0,j-1,maxdepth-1,tab);
    introspectivesort(j+1,id1,maxdepth-1,tab);
  }

}

void Print(int tab[Length]){
        for(int j=0;j<Length;j++){
          cout << tab[j] << " " ;
        }
        cout << endl;
}

int main(){
    ifstream reading;
    int *tab;
    char buffer;

    clock_t start=clock();  

    reading.open(mainbody);
    for(int i=0;i<AmountOfTabs;i++){
      tab=CreateTab(Length);
      for (int j = 0; j < Length; j++)
      {
        reading >> tab[j] >> buffer;
      }
      //MergeSort<int>(0,Length-1,tab)  ;
      //quicksort(0,Length-1,tab);
      //heapsort(Length,tab);
      //insertionsort(Length,tab);
      introspectivesort(0,Length-1,log(Length)*2/M_LN2,tab);
      //Print(tab);
      deleteTab(tab);
    }
    reading.close();
    
    
cout << endl << "Czas sortowania dla 100 tablic o rozmiarze " << Length << " :" << (double)(clock()-start)/CLOCKS_PER_SEC;
cout << endl;

}