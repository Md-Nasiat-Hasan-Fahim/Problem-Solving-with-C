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
      int N,W;
      cin>>N>>W;
      vector<pair<int,int>>vec;
      for(int i=0;i<N;i++)
      {
        int v,w;
        cin>>v>>w;
        vec.pb({v,w});
      }
      int dp[N+1][W+1];
      memset(dp,0,sizeof(dp));
      for(int i=0;i<N;i++)
      {
        for(int j=1;j<=W;j++)
        {
          if(i==0)
          {
            if(j>=vec[i].first) dp[i][j] = vec[i].second;
            continue;
          }
          dp[i][j] = dp[i-1][j];
          if(j-vec[i].first>-1) dp[i][j] = max(dp[i][j],vec[i].second+dp[i-1][j-vec[i].first]);
        }
      }
      cout<<dp[N-1][W]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
