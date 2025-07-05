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
      int n,w;
      cin>>n>>w;
      vector<pair<int,int>>vec;
      int sum = 0;
      for(int i=0;i<n;i++)
      {
        int u,v;
        cin>>u>>v;
        sum+=v;
        vec.pb({u,v});
      }
      int dp[n][sum+1];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<=sum;j++)
        {
          if(j==0) dp[i][j]=0;
          else dp[i][j] = INT_MAX;
        }
      }
      for(int i=0;i<n;i++)
      {
        for(int j=1;j<=sum;j++)
        {
          if(i==0)
          {
            if(j==vec[i].second) dp[i][j] = vec[i].first;
            continue;
          }
          dp[i][j] = dp[i-1][j];
          dp[i][j] = min(dp[i][j],dp[i-1][j-vec[i].second]+vec[i].first);
        }
      }
      int ans = 0;
      for(int i=0;i<n;i++)
      for(int j=0;j<=sum;j++)
      if(dp[i][j]<=w) ans = max(ans,j);
      cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
