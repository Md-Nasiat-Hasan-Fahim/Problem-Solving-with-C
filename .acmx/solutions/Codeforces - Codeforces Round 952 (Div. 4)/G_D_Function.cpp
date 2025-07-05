#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
}

int geosum(int a, int r, int n)
{
  int cal = POW(r,n);
  cal-=1;
  if(cal<0) cal+=mod;
  cal%=mod;
  cal = (cal*a)%mod;
  if(cal<0) cal+=mod;
  int div = POW(r-1,mod-2);
  cal = (cal*div)%mod;
  if(cal<0) cal+=mod;
  return cal%mod;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int l,r,k;
      cin>>l>>r>>k;
      int lim = 9/k;
      int st = geosum(lim,lim+1,r);
      // cout<<st<<endl;
      int ed = 0;
      if(l-1>-1) ed = geosum(lim,lim+1,l);
      int val = st - ed;
      val%=mod;
      if(val<0) val+=mod;
      cout<<val<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
