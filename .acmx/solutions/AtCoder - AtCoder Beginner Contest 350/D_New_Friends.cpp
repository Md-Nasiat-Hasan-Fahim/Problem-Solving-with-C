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

vector<vector<int>> graph;
vector<int> vis;
set<pair<int,int>>st;

int dfs(int x,int f)
{
  vis[x] = 1;
  int cnt = 1;
  for(auto c:graph[x])
  {
    // cout<<c<<" "<<x<<" "<<f<<endl;
    if(c!=f&&vis[c]) st.insert({min(c,x),max(c,x)});
    else if(!vis[c]) cnt+=dfs(c,x);
  }
  return cnt;
}

int abc(int n)
{
  return ((n-2)*(n-1))/2;
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
      int n,m;
      cin>>n>>m;
      graph.assign(n+1,vector<int>());
      vis.assign(n+1,0);
      for(int i=1;i<=m;i++)
      {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
      }
      int ans = 0;
      for(int i=1;i<=n;i++)
      {
        int cnt = 0;
        while(!st.empty()) st.erase(st.begin());
        if(!vis[i]) 
        {
          cnt = dfs(i,i);
          // cout<<i<<" "<<cnt<<" "<<st.begin()->first<<" "<<st.begin()->second<<endl;
          int ct = abc(cnt) - st.size();
          // cout<<i<<" "<<cnt<<" "<<ct<<" "<<st.size()<<endl;
          ans += max(0LL,ct);
        }
      }
      cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
