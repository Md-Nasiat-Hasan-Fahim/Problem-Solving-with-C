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

vector<string>graph;
vector<vector<int>>dp;
int n,m;

bool is_valid(int x, int y)
{
  return x>-1&&y>-1&&x<n&&y<m;
}

int dfs(int i, int j)
{
  if(dp[i][j]!=-1) return dp[i][j];
  if(graph[i][j]=='#') return dp[i][j]=0;
  int cnt = 0;
  if(is_valid(i,j+1)) cnt=dfs(i,j+1);
  if(is_valid(i+1,j)) cnt = (cnt+dfs(i+1,j))%mod;
  if(cnt<0) cnt+=mod;
  cnt%=mod;
  return dp[i][j]=cnt;
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
      cin>>n>>m;
      dp.assign(n+1,vector<int>(m+1,-1));
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        graph.pb(s);
      }
      dp[n-1][m-1]=1;
      cout<<dfs(0,0)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
