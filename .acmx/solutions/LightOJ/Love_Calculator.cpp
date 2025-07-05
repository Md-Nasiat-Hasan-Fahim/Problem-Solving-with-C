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
      string s1,s2;
      cin>>s1>>s2;
      s1 = '#'+s1;
      s2 = '#'+s2;
      int dp[s1.size()+1][s2.size()+1];
      int dp1[s1.size()+1][s2.size()+1];
      memset(dp1,0,sizeof(dp1));
      dp1[0][0]=1;
      for(int i=0;i<s1.size();i++) dp[i][0]=i,dp1[i][0]=1;
      for(int j=0;j<s2.size();j++) dp[0][j]=j,dp1[0][j]=1;
      for(int i=1;i<s1.size();i++)
      {
        for(int j=1;j<s2.size();j++)
        {
          if(s1[i]==s2[j])
          {
            dp[i][j] = min({1+dp[i-1][j-1],1+dp[i-1][j],1+dp[i][j-1]});
            if(dp[i][j] == 1+dp[i-1][j-1]) dp1[i][j]+=dp1[i-1][j-1];
            // if(dp[i][j] == 1+dp[i-1][j]) dp1[i][j]+=dp1[i-1][j];
            // if(dp[i][j] == 1+dp[i][j-1]) dp1[i][j]+=dp1[i][j-1];
          }
          else
          {
            dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
            if(dp[i][j] == 1+dp[i-1][j]) dp1[i][j]+=dp1[i-1][j];
            if(dp[i][j] == 1+dp[i][j-1]) dp1[i][j]+=dp1[i][j-1];
          }
        }
      }
      cout<<"Case "<<tttttttt<<": ";
      cout<<dp[s1.size()-1][s2.size()-1]<<" "<<dp1[s1.size()-1][s2.size()-1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
