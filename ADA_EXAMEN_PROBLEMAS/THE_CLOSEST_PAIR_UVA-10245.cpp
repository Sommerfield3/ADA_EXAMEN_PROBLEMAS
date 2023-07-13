#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
bool sortCoords(pair<float,float> a,pair<float,float> b){
  return a.first<b.first;
}
float distanceCoords(float x1,float y1,float x2,float y2){
  float dist=sqrt(pow((x2-x1),2)+(pow((y2-y1),2)));
  return dist;
}
float sinerg(pair<int,int> coords1[],int inic,int med,int fin, int min_izq, int min_der){
  float i_d;
  if(min_izq<min_der){
    i_d=min_izq;
  }else{
    i_d=min_der;
  }
  float traz=(coords1[med].first+coords1[med+1].first)/2.0;
  float minimT=i_d;
  for(int i=med+1;coords1[i].first<traz+i_d && i<=fin;i++){//Hallamos las distancias entre los puntos, siempre que sea conveniente
    for(int j=med;coords1[j].first>traz-i_d && j>=inic;j--){
      float aux=distanceCoords(coords1[i].first,coords1[i].second,coords1[j].first,coords1[j].second);
      if(aux<minimT)
        minimT=aux;
    }
  }
  return minimT;
}
float binaryMin(pair<int,int> coords1[],int inic,int fin){
  if(inic>=fin){
    return 10000;
  }
  int med=(inic+fin)/2;
  float min_izq=binaryMin(coords1,inic,med);
  float min_der=binaryMin(coords1,med+1,fin);
  return sinerg(coords1,inic,med,fin,min_izq,min_der);
}
void solve(int n,pair<int,int> coords1[]){
  float x,y;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    coords1[i]=make_pair(x,y);
  }
  sort(coords1,coords1+n,sortCoords);
  float Distance=binaryMin(coords1,0,n-1);
  if(Distance>=10000){
    cout<<"INFINITY"<<"\n";
    return;
  }
  cout<<fixed<<setprecision(4)<<Distance<<"\n";
}
int main() {
  int N;
  pair<int,int> coords1[10000];
  while(cin>>N){
    if(N==0)
      break;
    solve(N,coords1);
  }
}/*EL JUEZ EN LÍNEA NO PROCESÓ ESTE CÓDIGO POR UN FALLO DEL OJ*/