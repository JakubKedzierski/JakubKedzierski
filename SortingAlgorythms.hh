#pragma once
const int Length=100000;
using namespace std;

int *CreateTab(int n);
void deleteTab(int *tab);
void check(int tab[]);

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



template<typename Type>
void quicksort(int id0,int id1,Type tab[]){

/*podzial na polowki i piwot, piwot z ideksem j*/
  int halfscore=tab[(id0+id1)/2],j=id0;
  tab[(id0+id1)/2]=tab[id1];
  
  for(int i=id0;i<id1;i++){  
    
    if(tab[i]<halfscore){
      swap(tab[i],tab[j]);
      j++;
    }
  
  }
  tab[id1]=tab[j];
  tab[j]=halfscore;

  
  if(id0<j-1){
  quicksort(id0,j-1,tab);}

  if(j+1<id1){
  quicksort(j+1,id1,tab);}

}