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

struct ab{
  int u,v,w;
};

vector<ab>vec;
vector<int>par;

int dsu(int r)
{
  if(par[r]==r) return r;
  return par[r]=dsu(par[r]);
}

vector<vector<int>>tree;

int mst(int s)
{
  int val = 0;
  for(int i=vec.size()-1;i>-1;i--)
  {
    int pu = dsu(vec[i].u);
    int pv = dsu(vec[i].v);
    if(pu!=pv)
    {
      par[pv]=pu;
      val+=vec[i].w;
      tree[vec[i].u].pb(vec[i].v);
      tree[vec[i].v].pb(vec[i].u);
    }
  }
  return val;
}
queue<int>q;

void dfs(int x, int p)
{
  q.push(x);
  for(auto c:tree[x])
  {
    if(c!=p) dfs(c,x);
  }
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
      int n;
      cin>>n;
      int cnt = n*(n-1)/2;
      tree.assign(n+1,vector<int>());
      for(int i=0;i<cnt;i++)
      {
        int u,v,w;
        cin>>u>>v>>w;
        vec.pb({u,v,w});
      }
      sort(all(vec),[](ab a,ab b){
        return a.w>b.w;
      });
      par.assign(n+1,0);
      for(int i=1;i<=n;i++) par[i] = i;
      cout<<mst(1)<<endl;
      dfs(1,1);
      while(!q.empty()) cout<<q.front()<<" ",q.pop();
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
