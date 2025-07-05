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
      int val[n][3];
      for(int i=0;i<n;i++) cin>>val[i][0]>>val[i][1]>>val[i][2];
      int dp[n][3];
      dp[0][0]=val[0][0];
      dp[0][1]=val[0][1];
      dp[0][2]=val[0][2];
      for(int i=1;i<n;i++)
      {
        dp[i][0] = val[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = val[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = val[i][2]+max(dp[i-1][0],dp[i-1][1]);
      }
      cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
