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
int n;
vector<int>vec;

bool abc(int x)
{
  auto tem = vec;
  for(int i=n-1;i>1;i--)
  {
    int xyz = tem[i]-x;
    xyz = min(vec[i],xyz);
    xyz = max(0LL,xyz);

    xyz/=3;
    tem[i-1]+=xyz;
    tem[i-2]+=2*xyz;
  }
  for(int i=0;i<n;i++)
  {
    if(tem[i]<x) return false;
  }
  return true;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    // FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      cin>>n;
      vec.assign(n+1,0);
      for(int i=0;i<n;i++) cin>>vec[i];
      int lo = 1, hi = INT_MAX;
      while(hi-lo>1)
      {
        int mid = (hi+lo)/2;
        if(abc(mid)) lo = mid;
        else hi = mid;
      }
      if(abc(hi)) cout<<hi<<endl;
      else cout<<lo<<endl;
      // cout<<abc(2)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
