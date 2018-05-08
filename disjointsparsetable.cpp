#include<bits/stdc++.h>
using namespace std;
using Int = long long;

//BEGIN CUT HERE
template<typename T>
struct DisjointSparseTable{
  using F = function<T(T,T)>;
  vector<vector<T> > dat;
  vector<int> ht;
  const F f;
  DisjointSparseTable(){}
  DisjointSparseTable(int n,F f):f(f){init(n);}
  
  void init(int n){
    int h=1;
    while((1<<h)<=n) h++;
    dat.assign(h,vector<T>(n));
    ht.assign((1<<h),0);
    for(int j=2;j<=(1<<h);j++) ht[j]=ht[j>>1]+1;
  }
  
  void build(int n,vector<T> &v){
    int h=1;
    while((1<<h)<=n) h++;
    for(int i=0;i<n;i++) dat[0][i]=v[i];
    for(int i=1;i<h;i++){
      int s=1<<i;
      for(int j=0;j<n;j+=s<<1){
	int t=min(j+s,n);
	dat[i][t-1]=v[t-1];
	for(int k=t-2;k>=j;k--) dat[i][k]=f(v[k],dat[i][k+1]);
	if(n<=t) break;
	dat[i][t]=v[t];
	int r=min(t+s,n);
	for(int k=t+1;k<r;k++) dat[i][k]=f(dat[i][k-1],v[k]);
      }
    }
  }

  T query(int l,int r){
    if(l>=--r) return dat[0][l];
    return f(dat[ht[l^r]][l],dat[ht[l^r]][r]);
  }
  
};
//END CUT HERE


signed ARC023_D(){
  int n,m;
  cin>>n>>m;
  vector<Int> a(n),x(m);
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>x[i];

  DisjointSparseTable<Int>::F f=[](Int a,Int b){return __gcd(a,b);};
  DisjointSparseTable<Int> dst(n,f);
  dst.build(n,a);
  
  map<Int, Int> ans;
  for(int i=0;i<n;i++){
    int l=i;
    Int pre=a[i],lst=dst.query(i,n);
    while(lst!=pre){
      int r=n,pl=l;
      while(l+1<r){
	int m=(l+r)>>1;
	if(dst.query(i,m)!=pre) r=m;
	else l=m;
      }
      ans[pre]+=l-pl;
      pre=dst.query(i,r);
    }
    ans[lst]+=n-l;
  }
  
  for(int i=0;i<m;i++) cout<<ans[x[i]]<<endl;
  return 0;
}
/*
  verified on 2018/05/08
  https://beta.atcoder.jp/contests/arc023/tasks/arc023_4
*/


signed CODECHEF_SEGPROD(){
  int T;
  scanf("%d",&T);
    
  Int p;
  DisjointSparseTable<Int>::F f=[&](Int a,Int b){return a*b%p;};
  DisjointSparseTable<Int> dst(1e6+10,f);
    
  for(int t=1;t<=T;t++){
    int n,q;
    scanf("%d %lld %d",&n,&p,&q);
    vector<Int> v(n);
    for(int i=0;i<n;i++) scanf("%lld",&v[i]);
    vector<int> b(q/64+2);
    for(int i=0;i<(q/64+2);i++) scanf("%d",&b[i]);
    
    dst.build(n,v);
    
    int x=0,l=0,r=0;
    for(int i=0;i<q;i++){
      if(i%64==0){
	l=(b[i/64]+x)%n;
	r=(b[i/64+1]+x)%n;
      }else{
	l=(l+x)%n;
	r=(r+x)%n;
      }
      if(l>r) swap(l,r);
      x=(dst.query(l,r+1)+1)%p;
    }
    printf("%d\n",x);    
  }
  return 0;
}
/*
  verified on 2018/05/08
  https://www.codechef.com/problems/SEGPROD
*/

//INSERT ABOVE HERE
signed main(){
  //ARC023_D();
  CODECHEF_SEGPROD();
  return 0;
}
