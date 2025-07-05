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

int n,m,k;

bool abc(int x)
{
  int lc = (n*m)/__gcd(n,m);
  int cnt = (x/n) + (x/m) - 2*(x/lc);
  return cnt>=k;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      cin>>n>>m>>k;
      int hi = 2,lo = 0;
      while(!abc(hi)) hi*=2;
      while(hi-lo>1)
      {
        int mid = lo + (hi-lo)/2;
        if(abc(mid)) hi = mid;
        else lo = mid;
      }
      // cout<<abc(8)<<endl;
      // cout<<lo<<" "<<hi<<endl;
      if(abc(lo)) cout<<lo<<endl;
      else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
