#include "SortingAlgorythms.hh"
#include <iostream>
using namespace std;

void check(int tab[]){
  for(int i=0;i<Length-1;i++){
    if(tab[i+1]<tab[i]){
    cout << endl << endl << "error error" << endl; 
    return;}
  }
}

int *CreateTab(int n){
    return new int[n];
}

void deleteTab(int *tab){
    delete [] tab;
}