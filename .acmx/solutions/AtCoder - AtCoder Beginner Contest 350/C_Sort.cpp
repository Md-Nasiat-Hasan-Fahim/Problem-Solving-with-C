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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      vector<int>vec(n+1),pos(n+1);
      for(int i=1;i<=n;i++)
      {
        cin>>vec[i];
        pos[vec[i]] = i;
      }
      vector<pair<int,int>> ans;
      for(int i=1;i<=n;i++)
      {
        if(vec[i]!=i)
        {
          int ps = pos[i];
          if(i<ps) ans.pb({i,ps});
          else ans.pb({ps,i});
          int v1 = vec[i];
          int v2 = vec[ps];
          pos[i] = i;
          pos[vec[i]] = ps;
          vec[i] = i;
          vec[ps] = v1;
        }
      }
      cout<<ans.size()<<endl;
      for(auto [a,b]:ans) cout<<a<<" "<<b<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
