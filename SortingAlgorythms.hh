#pragma once
const int Length=10;
#include <iostream>
#include <iomanip>  
using namespace std;



template<typename Type>
void check(Type tab[]){
  for(int i=0;i<Length-1;i++){
    if(tab[i+1]<tab[i]){
    cout << endl << endl << "error error gdzies w poblizu indeksu " << i << endl; 
    return;}
  }
}

template<typename Type>
Type* CreateTab(int n){
    return new Type[n];
}

template<typename Type>
void deleteTab(Type *tab){
    delete [] tab;
}

template<typename Type>
void Print(Type* tab,int n){
        for(int j=0;j<n;j++){
          cout << setw(5) << tab[j]  ;
        }
        cout << endl;
}

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
int FindingPivot(int id0,int id1,Type tab[],bool order){
  int halfscore=tab[(id0+id1)/2],j=id0;
  
  tab[(id0+id1)/2]=tab[id1];
  
  for(int i=id0;i<id1;i++){  
  
    if(order){
      if(tab[i]<halfscore){
        swap(tab[i],tab[j]);
        j++;
      }
    }else{
        if(tab[i]>halfscore){
        swap(tab[i],tab[j]);
        j++;
        }
    }
  
  }

  tab[id1]=tab[j];
  tab[j]=halfscore;
return j;
}


template<typename Type>
void quicksort(int id0,int id1,Type tab[],bool order){

/*podzial na polowki i piwot, piwot z ideksem j*/
  int j=FindingPivot(id0,id1,tab,order);
  
  if(id0<j-1){
  quicksort(id0,j-1,tab,order);}

  if(j+1<id1){
  quicksort(j+1,id1,tab,order);}

}

/*Algorytmy sortowania przygotowane na potrzeby sortowania introspektywnego */

/*Tworzenie kopca na potrzeby sortowania przez kopcowanie*/
template<typename Type>
void heapify(int n,int id,Type tab[]){
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

template<typename Type>
void heapsort(int n,Type tab[]) 
{ 
    for (int i=n/2-1;i>=0;i--) 
        heapify(n,i,tab); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(tab[0], tab[i]); 
        heapify(i,0,tab); 
    } 
} 

/* sortowanie przez wstawianie na uzytek sortowania introspektywnego */
template<typename Type>
void insertionsort(int id0,int id1,Type tab[]){
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

template<typename Type>
void introspectivesort(int id0,int id1,int maxdepth,Type tab[],bool order){
  int j;
  if((id1-id0)<=0) return;

  if(id1-id0>16){
    
    if(maxdepth==0){
    heapsort((id1-id0+1),tab+id0);
    }
    
    maxdepth--;
    j=FindingPivot(id0,id1,tab,order);
    introspectivesort(id0,j-1,maxdepth,tab,order);
    introspectivesort(j+1,id1,maxdepth,tab,order);
   
  }else{
  // Dla malych tablic sortujemy przez wstawianie
  insertionsort(id0,id1+1,tab);
  }
}