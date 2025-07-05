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
queue<char>q;
int n,m;

void chk(int i, int j, vector<vector<int>> &dp,string &s, string &t)
{
  if(i==n||j==m) return;
  int mx = max({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
  if(s[i]==t[j])
  {
    q.push(s[i]);
    chk(i+1,j+1,dp,s,t);
  }
  else if(dp[i+1][j]==mx) chk(i+1,j,dp,s,t);
  else if(dp[i][j+1]==mx) chk(i,j+1,dp,s,t);
  else chk(i+1,j+1,dp,s,t);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      string s,t;
      cin>>s>>t;
      n = s.size();
      m = t.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1));
      for(int i=n-1;i>-1;i--)
      {
        for(int j=m-1;j>-1;j--)
        {
          dp[i][j] = max({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
          if(s[i]==t[j]) dp[i][j] = max(dp[i][j],1+dp[i+1][j+1]);
        }
      }
      chk(0,0,dp,s,t);
      while(!q.empty())
      {
        cout<<q.front();
        q.pop();
      }
      cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
