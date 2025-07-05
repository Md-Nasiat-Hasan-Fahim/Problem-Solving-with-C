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

vector<vector<pair<int,int>>>graph;
vector<int>vis,dp;
int n,m;

int dfs(int x)
{
    if(x==n) return LONG_LONG_MAX;
    if(vis[x])
    {
        if(dp[x]==2) return dp[x];
        return LONG_LONG_MIN;
    }
    vis[x]=1;
    int mx = -1;
    for(auto [b,w]:graph[x])
    {
        int mnx = dfs(b);
        if(mnx==LONG_LONG_MIN) continue;
        mx = max(mx,min(w,mnx));
        //if(x==1) cout<<mx<<" "<<x<<" "<<mnx<<" "<<w<<endl;
    }
    vis[x]=2;
    //cout<<x<<" "<<mx<<endl;
    return dp[x]=mx;
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
        vis.assign(n+1,0);
        dp.assign(n+1,-1);
        graph.assign(n+1,vector<pair<int,int>>());
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            if(a==b) continue;
            graph[a].pb({b,w});
            graph[b].pb({a,w});
        }
        cout<<dfs(1)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
