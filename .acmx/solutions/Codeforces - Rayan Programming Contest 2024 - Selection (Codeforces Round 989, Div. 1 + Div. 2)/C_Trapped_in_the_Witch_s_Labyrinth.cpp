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
vector<string>vec;
vector<vector<int>>vis,path;
vector<pair<int,int>>mv = {{1,0},{0,1},{-1,0},{0,-1}};
bool is_valid(int x, int y)
{
  return x>-1&&x<n&&y>-1&&y<m;
}

bool dfs(int x, int y)
{
  vis[x][y] = 1;
  if(vec[x][y]=='U')
  {
    int a = x-1;
    int b = y;
    if(is_valid(a,b))
    {
      if(vis[a][b]) path[x][y]+=path[a][b];
      else path[x][y]+=dfs(a,b);
    }
    else path[x][y] += 1;
  }
  else if(vec[x][y]=='D')
  {
    int a = x+1;
    int b = y;
    if(is_valid(a,b))
    {
      if(vis[a][b]) path[x][y]+=path[a][b];
      else path[x][y]+=dfs(a,b);
    }
    else path[x][y] += 1;
  }
  else if(vec[x][y]=='R')
  {
    int a = x;
    int b = y+1;
    if(is_valid(a,b))
    {
      if(vis[a][b]) path[x][y]+=path[a][b];
      else path[x][y]+=dfs(a,b);
    }
    else path[x][y] += 1;
  }
  else if(vec[x][y]=='L')
  {
    int a = x;
    int b = y-1;
    if(is_valid(a,b))
    {
      if(vis[a][b]) path[x][y]+=path[a][b];
      else path[x][y]+=dfs(a,b);
    }
    else path[x][y]++;
  }
  else if(vec[x][y]=='?')
  {
    for(int i=0;i<mv.size();i++)
    {
      int a = x + mv[i].first;
      int b = y + mv[i].second;
      if(is_valid(a,b))
      {
        if(vis[a][b]) path[x][y]+=path[a][b];
        else path[x][y]+=dfs(a,b);
      }
      else path[x][y]++;
    }
  }
  return path[x][y];
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
      vec.clear();
      cin>>n>>m;
      vis.assign(n+1,vector<int>(m+1));
      path.assign(n+1,vector<int>(m+1));
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        vec.pb(s);
      }
      int cnt = 0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(!vis[i][j]) dfs(i,j);
        }
      }
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(path[i][j]==0) cnt;
        }
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
