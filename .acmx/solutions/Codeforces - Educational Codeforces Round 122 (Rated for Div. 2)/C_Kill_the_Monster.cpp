#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int int64_t
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int hc,dc,hm,dm;
      cin>>hc>>dc>>hm>>dm;
      int k,w,a;
      cin>>k>>w>>a;
      bool ans = false;
      for(int i=0;i<=k;i++)
      {
        int th = hc+(i*a);
        int td = dc+((k-i)*w);
        // cout<<i<<" "<<th<<" "<<td<<endl;
        int tern = th/dm + (th%dm!=0);
        if(td*tern>=hm) ans = true;
      }
      if(ans) YES;
      else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
