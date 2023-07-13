#include <bits/stdc++.h>
using namespace std;
int withdraw(int b[],int tam){
  int sum=0;
  int numMonedas=0;
  for(int i=0;i<tam;i++){
    if(i==tam-1 || sum+b[i]<b[i+1]){
      numMonedas++;
      sum=sum+b[i];
    }
    if(sum==0)
      break;
  }
  return numMonedas;
}
void solve(){
  int a;
  cin>>a;
  int b[a];
  for(int i=0;i<a;i++){
    cin>>b[i];
  }
  int tam=sizeof(b)/sizeof(b[0]);
  cout<<withdraw(b,tam)<<"\n";
}
int main() {
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    solve();
  }
}