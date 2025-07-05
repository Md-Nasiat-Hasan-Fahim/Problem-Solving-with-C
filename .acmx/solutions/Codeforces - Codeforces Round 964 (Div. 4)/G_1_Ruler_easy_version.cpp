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

bool abc(int x, int y)
{
  cout<<"? "<<x<<" "<<y<<endl;
  int a;
  cin>>a;
  return a>(x*y);
}

int tern(int &hi, int &lo)
{
  bool m1 = abc((2*lo+hi)/2,2);
  bool m2 = abc((lo+2*hi)/2,2);
  if(m1&&m2)
  {
    hi = (2*lo+hi)/2;
  }
  else if(!m1&&m2)
  {
    lo = (2*lo+hi)/2;
    hi = (lo+2*hi)/2;
  }
  else if(m1&&!m2)
  {
    hi = (2*lo+hi)/2;
  }
  else
  {
    lo = (2*lo+hi)/2;
  }
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
      int hi = 999,lo = 1;
      tern(hi,lo);
      tern(hi,lo);
      while(hi-lo>1)
      {
        int mid = (hi+lo)/2;
        if(abc(mid,2)) hi = mid;
        else lo = mid;
      }
    cout<<"! "<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
