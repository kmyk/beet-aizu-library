// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
// verification-helper: ERROR 0.00000001

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test


// Projection
signed main(){
  Point p1,p2;
  cin>>p1>>p2;
  int q;
  cin>>q;
  while(q--){
    Point p;
    cin>>p;
    cout<<project(Line(p1,p2),p)<<endl;
  }
  return 0;
}
