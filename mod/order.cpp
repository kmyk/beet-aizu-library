#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "pow.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// mod can be composite numbers
template<typename T>
T order(T x,const T MOD){
  static map<T, vector<T>> dp;
  static map<T, T> phi;

  vector<T> &ps=dp[MOD];
  if(ps.empty()){
    T res=MOD,n=MOD;
    for(T i=2;i*i<=n;i++){
      if(n%i) continue;
      while(n%i==0) n/=i;
      res=res/i*(i-1);
    }
    if(n!=1) res=res/n*(n-1);
    phi[MOD]=res;

    for(T i=2;i*i<=res;i++){
      if(res%i) continue;
      while(res%i==0) res/=i;
      ps.emplace_back(i);
    }
    if(res!=1) ps.emplace_back(res);
  }

  T res=phi[MOD];
  for(T p:ps){
    while(res%p==0){
      if(mod_pow(x,res/p,MOD)!=1) break;
      res/=p;
    }
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
