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
const int mod = 100000007;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n,k;
      cin>>n>>k;
      vector<int>val(n+2),cnt(n+2);
      for(int i=1;i<=n;i++) cin>>val[i];
      for(int i=1;i<=n;i++) cin>>cnt[i];
      vector<vector<int>>dp(n+3,vector<int>(k+3,0LL));
      dp[0][0]=1;
      for(int i=1;i<=n;i++)
      {
        for(int j=0;j<=k;j++)
        {
          for(int p = 0;p<=cnt[i];p++)
          {
            if(i-1>-1&&j-p*val[i]>-1) dp[i][j]+=dp[i-1][j-p*val[i]];
              dp[i][j]%=mod;
          }
        }
      }
      // for(int i=1;i<=n;i++)
      // {
      //   for(int j=0;j<=k;j++) cout<<dp[i][j]<<" ";
      //   cout<<endl;
      // }
      cout<<"Case "<<tttttttt<<": ";
      cout<<dp[n][k]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
