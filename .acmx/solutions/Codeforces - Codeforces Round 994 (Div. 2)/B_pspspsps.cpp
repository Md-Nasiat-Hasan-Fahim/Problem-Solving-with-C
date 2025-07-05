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
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      string s;
      cin>>s;
      int ip = -1, is = -1, ctp = 0, cts = 0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='s') is = i, cts++;
      }
      for(int i=n-1;i>-1;i--)
      {
        if(s[i]=='p') ip = i, ctp++;
      }
      if(ctp==0||cts==0)
      {
        YES;
        continue;
      }
      if(ctp>1&&cts>1)
      {
        NO;
        continue;
      }
      if(ip<is)
      {
        NO;
        continue;
      }
      if(ctp==1&&ip!=n-1&&is!=0)
      {
        NO;
        continue;
      }
      if(cts==1&&is!=0&&ip!=n-1)
      {
        NO;
        continue;
      }
      YES;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
