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
      string s;
      cin>>s;
      int n = s.size();
      int dp[n][n];
      memset(dp,0,sizeof(dp));
      for(int j=0;j<n;j++)
      {
        for(int i=j;i>-1;i--)
        {
          if(j==i)
          {
            dp[i][j]=1;
            continue;
          }
          int cnt = 0;
          for(int k=i;k<=j;k++)
          {
            if(k==i)
            {
              // dp[i][k] = 1;
              // dp[i][j] = max(dp[i][j],1 + dp[k+1][j]);
              continue;
            }
            if(s[i]==s[k])
            {
              cnt+=1;
              if(i+1<=k-1) cnt+=dp[i+1][k-1];
            }
          }
          dp[i][j]=1+cnt+dp[i+1][j];
        }
      }
      cout<<"Case "<<tttttttt<<": ";
      cout<<dp[0][n-1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
