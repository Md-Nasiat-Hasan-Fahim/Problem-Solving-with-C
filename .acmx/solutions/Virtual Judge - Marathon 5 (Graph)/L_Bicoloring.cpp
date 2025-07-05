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

vector<vector<int>>graph;
vector<int>vis;
bool flag;

void dfs(int x, int fg)
{
    vis[x]=fg;
    for(auto c: graph[x])
    {
        if(vis[c]==0) dfs(c,-fg);
        else
        {
            if(vis[c]==fg) flag = false; 
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    while(1)
    {
        int n;
        cin>>n;
        if(n==0) break;
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        flag=true;
        int m;
        cin>>m;
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        dfs(0,1);
        if(flag) cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
