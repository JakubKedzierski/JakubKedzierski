#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip> 
#include <vector> 
using namespace std;
const char* mainbody="tabs.csv";
const int AmountOfTabs=100;
const int Length=100;

template<typename Type>
void Merge(int id0,int id1,int half,Type tab[]){
    int left=id0,right=half;
    Type help[Length];
   
    for(int i=id0;i<=id1;i++){
       if( (left==half) || ( (right<=id1) && (tab[left]>tab[right]) ) )
        {
            help[i]=tab[right];
            right++;
           
        }else{
           help[i]=tab[left];
           left++;
        }  

    }   

    for(int i=id0;i<=id1;i++)
    tab[i]=help[i];

}
template<typename Type>
void MergeSort(int id0,int id1,Type tab[]){
    int half=(id0+id1)/2;  // polowka problemu

  if(id1!=id0){   // dopoki sa wiecej niz 1 elementy
    MergeSort<Type>(id0,half,tab);  // sortujemy pierwsza czesc problemu
    MergeSort<Type>(half+1,id1,tab);  // sortujemy druga czesc problemu
    Merge<Type>(id0,id1,half+1,tab); // laczymy dwa posortowane problemy
  }

}

void quicksort(int id0,int id1,int tab[]){

/*podzial na polowki i piwot, piwot z ideksem j*/
  int halfscore=tab[(id0+id1)/2],j=0;;
  swap(tab[(id0+id1)/2],tab[id1]);
  
  for(int i=0;i<id1-1;i++){  
    if(tab[i]<halfscore){
      swap(tab[i],tab[j]);
      j++;
    }
  }
  swap(tab[id1],tab[j]);

}



void check(int tab[]){
  for(int i=0;i<Length-1;i++){
    if(tab[i+1]<tab[i])
    cout << "error error"; 
  }
}


void Print(int tab[AmountOfTabs][Length]){
      for(int i=0;i<AmountOfTabs;i++){
        for(int j=0;j<Length;j++){
          cout << tab[i][j] << " " ;
        }
        cout << endl;
      }
}

int main(){
    ifstream reading;
    int tab[AmountOfTabs][Length];
    char buffer;

    reading.open(mainbody);
    for(int i=0;i<AmountOfTabs;i++){
      for (int j = 0; j < Length; j++)
      {
        reading >> tab[i][j] >> buffer;
      }
        
    }
    reading.close();
    
    clock_t start=clock();  
    
    for(int j=0;j<AmountOfTabs;j++){
     // quicksort(0,Length-1,tab);
      MergeSort<int>(0,Length-1,tab[j])  ;
    }
     
    
cout << endl << "Czas sortowania dla 100 tablic o rozmiarze " << Length << " :" << (double)(clock()-start)/CLOCKS_PER_SEC;
cout << endl;

}