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

vector<vector<int>>graph;
vector<int>vis;
vector<int>vec;
queue<int>q;
unordered_map<int,int,custom_hash>mp;

void dfs(int x, int lev)
{
  vis[x]=1;
  vec.pb(lev);
  mp[x] = lev;
  for(auto c:graph[x])
  {
    if(!vis[c]) dfs(c,lev+1);
  }
  if(graph[x].size()==1) q.push(x);
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
      int n;
      cin>>n;
      graph.assign(n+1,vector<int>());
      vis.assign(n+1,0);
      for(int i=0;i<n-1;i++)
      {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
      }
      dfs(1,0);
      cout<<vec.size()<<endl;
      sort(all(vec));
      int cnt = INT_MAX;
      while(!q.empty())
      {
        auto a = q.front();
        q.pop();
        cnt = min(cnt,vec.end()-upper_bound(all(vec),mp[a]));
        cout<<a<<" "<<mp[a]<<" "<<cnt<<endl;
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
