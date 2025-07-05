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

int n,m;
vector<vector<int>>graph,vis;
vector<pair<int,int>>mv = {{1,0},{0,1},{-1,0},{0,-1}};
unordered_map<pair<vector<vector<int>>,pair<int,int>>,int> dp1;
unordered_map<pair<vector<vector<int>>,pair<int,int>>,int> dp2;

bool is_valid(int x, int y)
{
  return x>-1&&x<n&&y>-1&&y<m;
}

int dfs2(int x, int y)
{
  if(x==0&&y==0) return graph[x][y];
  // if(dp2[x][y]!=-1) return dp2[x][y];
  if(dp2[{vis,{x,y}}]) return dp2[{vis,{x,y}}];
  int cnt = 0;
  for(int i=2;i<4;i++)
  {
    if(is_valid(x+mv[i].first,y+mv[i].second)&&!vis[x+mv[i].first][y+mv[i].second])
    {
      cnt = max(cnt,dfs2(x+mv[i].first,y+mv[i].second));
    }
  }
  return dp2[{vis,{x,y}}]=cnt+graph[x][y];
}

int dfs1(int x, int y)
{
  // cout<<x<<" "<<y<<endl;
  if(x==n-1&&y==m-1) return dfs2(x,y);
  // if(dp1[x][y]!=-1) return dp1[x][y];
  if(dp1[{vis,{x,y}}]) return dp1[{vis,{x,y}}];
  vis[x][y] = 1;
  int cnt = 0;
  for(int i=0;i<2;i++)
  {
    if(is_valid(x+mv[i].first,y+mv[i].second))
    {
      cnt = max(cnt,dfs1(x+mv[i].first,y+mv[i].second));
    }
  }
  vis[x][y] = 0;
  return dp1[{vis,{x,y}}]=cnt+graph[x][y];
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      cin>>n>>m;
      graph.assign(n+1,vector<int>(m+1,0));
      vis.assign(n+1,vector<int>(m+1,0));
      // dp1.assign(n+1,vector<int>(m+1,-1));
      // dp2.assign(n+1,vector<int>(m+1,-1));
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++) cin>>graph[i][j];
      }
      cout<<"Case "<<tttttttt<<": ";
      cout<<dfs1(0,0)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
