#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector> 
using namespace std;
const char* mainbody="tabs.txt";
const int Length=10000;


void Merge(int id0,int id1,int half,int tab[]){
    int left=id0,right=half,help[id1];
   
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

void MergeSort(int id0,int id1,int tab[]){
    int half=(id0+id1)/2;  // polowka problemu

  if(id1!=id0){   // dopoki sa wiecej niz 1 elementy
    MergeSort(id0,half,tab);  // sortujemy pierwsza czesc problemu
    MergeSort(half+1,id1,tab);  // sortujemy druga czesc problemu
    Merge(id0,id1,half+1,tab); // laczymy dwa posortowane problemy
  }

}


int main(){
    clock_t start=clock();
    int AmountOfTabs=100;
    srand( time( NULL ) );
    int tab[Length];

    for(int j=0;j<AmountOfTabs;j++){

      for(int i=0;i<Length;i++){
        tab[i] = rand()  %1000 ;
      }
      
      MergeSort(0,Length-1,tab)  ;
    }


cout << endl << "Czas sortowania dla 100 tablic o rozmiarze " << Length << " :" << (double)(clock()-start)/CLOCKS_PER_SEC;
cout << endl;

}