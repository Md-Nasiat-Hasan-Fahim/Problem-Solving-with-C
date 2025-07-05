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

vector<pair<int,int>>vec;
int n,h;

bool abc(int x)
{
  int cnt = 0;
  for(int i = 0;i<n;i++)
  {
    int a = ceil(1.0*x/vec[i].second)*vec[i].first;
    cnt+= a;
  }
  return cnt>=h;
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
      cin>>h>>n;
      vec.assign(n+1,pair<int,int>());
      for(int i=0;i<n;i++) cin>>vec[i].first;
      for(int i=0;i<n;i++) cin>>vec[i].second;
      int lo = 1, hi = 1;
      while(!abc(hi)) hi = 2*hi;
      while(hi-lo>1)
      {
        int mid = (hi+lo)/2;
        if(abc(mid)) hi = mid;
        else lo = mid;
      }
      if(abc(lo)) cout<<lo<<endl;
      else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
