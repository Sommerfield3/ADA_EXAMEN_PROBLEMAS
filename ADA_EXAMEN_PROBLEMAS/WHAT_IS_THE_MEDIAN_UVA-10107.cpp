#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array,int inicio,int medio,int fin){
  int izquierda=medio-inicio+1;
  int derecha=fin-medio;
  vector<int> izqArr(izquierda);
  vector<int> derArr(derecha);
  for (int i=0; i<izquierda; i++){ 
    izqArr[i]=array[inicio+i]; 
  }
  for (int j=0; j<derecha; j++){
    derArr[j]=array[medio+1+j]; 
  }
  int actual=inicio;
  int izqC=0;
  int derC=0;
  while(izqC<izquierda && derC<derecha){
    if(izqArr[izqC]<=derArr[derC]){
      array[actual]=izqArr[izqC];
      izqC++;
    }else{
      array[actual]=derArr[derC];
      derC++;
    }
    actual++;
  }
  while(izqC<izquierda){
    array[actual]=izqArr[izqC];
    izqC++;
    actual++;
  }
  while(derC<derecha){
    array[actual]=derArr[derC];
    derC++;
    actual++;
  }
}
void mergeSort(vector<int>& array,int inicio,int fin){
  if(inicio>=fin){
    return;
  }
  int medio=inicio+(fin-inicio)/2;
  mergeSort(array,inicio,medio);
  mergeSort(array,(medio+1),fin);
  merge(array,inicio,medio,fin);
}
void solve(vector<int>& V){
  int a;
  while(cin>>a){
    if(a==0)
      return;
    V.push_back(a);
    mergeSort(V,0,V.size()-1);
    if(V.size()%2==0){
      int mediana=(V[V.size()/2-1]+V[V.size()/2])/2;
      cout<<mediana<<"\n";
      continue;
    }
    cout<<V[V.size()/2]<<"\n";
  }
}
int main() {
  vector<int> V;
  int count=0;
  solve(V);
}