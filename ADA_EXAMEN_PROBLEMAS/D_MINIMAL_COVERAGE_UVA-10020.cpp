#include <bits/stdc++.h>
using namespace std;
void solve(){
  int M;
  cin>>M;
  map<int,int> Trazos;
  int va,vb;
  int count=0;
  while(cin>>va>>vb){
    if(!va && !vb){
      break; 
    }
    if(Trazos.find(va)==Trazos.end() || vb>Trazos[va]){//Asignando siempre el mayor rango
      Trazos[va]=vb;
    }
  }
  vector<pair<int,int>> V;
  int current_lower=0;
  int pnumy=0; 
  int numx=0; 
  int numy=0;
  while(numy<M){
    pnumy=numy;
    for(auto it=Trazos.begin();it!=Trazos.end();++it){
      if(it->first<=current_lower && it->second>numy){
        numx=it->first;
        numy=it->second;
      }
      if(it->first>current_lower){
        break;
      }
    }
    current_lower=numy;
    if(pnumy==numy){//no hay más a procesar
      /*V.clear(),count++;*/
      cout<<"0\n";
      return;
    }
    V.push_back(make_pair(numx,numy));
  }
  cout<<V.size()<<"\n";
  for(int i=0;i<V.size();i++){
    cout<<V[i].first<<" "<<V[i].second<<"\n";
  }
}
int main() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    solve();
    cout<<"\n";
  }
}
