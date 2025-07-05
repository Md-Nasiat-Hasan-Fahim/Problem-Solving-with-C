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
      int n,m;
      cin>>n>>m;
      vector<int>vec(m),comp(m);
      for(int i=0;i<m;i++) cin>>comp[i];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          int a;
          cin>>a;
          vec[j]+=a;
        }
      }
      bool ans = true;
      for(int i=0;i<m;i++)
      {
        if(comp[i]>vec[i]) ans=false;
      }
      if(ans) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
