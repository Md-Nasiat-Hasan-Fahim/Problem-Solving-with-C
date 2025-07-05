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


vector<vector<int>>vec,vis;
vector<pair<int,int>>mv = {{0,1},{1,0},{0,-1},{-1,0}};

bool is_valid(int x, int y, int n, int m)
{
  return x>-1&&x<m&&y>-1&&y<n;
}

vector<int>res;
int fg;

void dfs(int x, int y,int n, int m)
{
  vis[x][y] = 1;
  res[fg++]=vec[x][y];
  for(int i=0;i<mv.size();i++)
  {
    int a = x+mv[i].first;
    int b = y+mv[i].second;
    if(is_valid(a,b,n,m)&&!vis[a][b])
    {
      dfs(a,b,n,m);
      break;
    }
  }
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
      int n,m;
      cin>>n>>m;
      vec.assign(n+1,vector<int>(m+1));
      vis.assign(n+1,vector<int>(m+1,0));
      res.assign(2*(n+m-2+5),0);
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++) cin>>vec[i][j];
      }
      for(int i=0;i<max(n,m);i++)
      {
        fg = 0;
        if(is_valid(i,i,n-i,m-i)&&!vis[i][i])
        dfs(i,i,n-i,m-i);
        for(int j=0;j<fg;j++) cout<<res[j]<<" ";
        cout<<endl;
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
