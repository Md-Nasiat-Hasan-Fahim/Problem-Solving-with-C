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
vector<string>graph;
vector<vector<int>>vis,flag;
queue<pair<int,int>>q;
vector<pair<int,int>> mv = {{1,0},{0,1},{-1,0},{0,-1}};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool is_valid(int x,int y)
{
  return x>-1&&x<n&&y>-1&&y<m;
}

int dfs1(int x, int y)
{
  int cnt = 1;
  q.push({x,y});
  vis[x][y]=1;
  for(int i=0;i<4;i++)
  {
    auto [a,b] = mv[i];
    if(is_valid(x+a,y+b)&&!vis[x+a][y+b]&&graph[x+a][y+b]=='#')
    {
      cnt+=dfs1(x+a,y+b);
    }
  }
  return cnt;
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
      graph.clear();
      int fg = 1;
      vis.assign(n+1,vector<int>(m+1));
      flag.assign(n+1,vector<int>(m+1));
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        graph.pb(s);
      }
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(graph[i][j]=='#'&&!vis[i][j])
          {
            int cnt = dfs1(i,j);
            while(!q.empty())
            {
              auto [a,b] = q.front();
              q.pop();
              vis[a][b]=cnt;
              flag[a][b]=fg;
            }
            fg++;
          }
        }
      }
      multiset<int>same;
      set<int>side;
      unordered_map<int,int,custom_hash>mp;
      int mx = 0;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++) mp[flag[i][j]]++;
      }
      // for(auto [c,v]:mp)
      // {
      //   cout<<c<<" "<<v<<endl;
      // }
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(is_valid(i-1,j)&&graph[i-1][j]=='#')
          {
            side.insert(flag[i-1][j]);
          }
          if(is_valid(i+1,j)&&graph[i+1][j]=='#')
          {
            side.insert(flag[i+1][j]);
          }
        }
        for(int j=0;j<m;j++)
        {
          same.insert(flag[i][j]);
        }
        int ct = m;
        for(auto c:side)
        {
          ct+=mp[c];
          ct-=same.count(c);
          // cout<<c<<" "<<mp[c]<<" "<<ct<<endl;
        }
        side.clear();
        same.clear();
        mx = max(mx,ct);
        // cout<<i<<" "<<ct<<endl;
      }
      for(int j=0;j<m;j++)
      {
        for(int i=0;i<n;i++)
        {
          if(is_valid(i,j-1)&&graph[i][j-1]=='#')
          {
            side.insert(flag[i][j-1]);
          }
          if(is_valid(i,j+1)&&graph[i][j+1]=='#')
          {
            side.insert(flag[i][j+1]);
          }
        }
        for(int i=0;i<n;i++)
        {
          same.insert(flag[i][j]);
        }
        int ct = n;
        for(auto c:side)
        {
          ct+=mp[c];
          ct-=same.count(c);
          // cout<<c<<" "<<mp[c]<<" "<<ct<<endl;
        }
        side.clear();
        same.clear();
        mx = max(mx,ct);
        // cout<<j<<" "<<ct<<endl;
      }
      cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
