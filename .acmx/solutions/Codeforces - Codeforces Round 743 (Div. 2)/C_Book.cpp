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

vector<vector<int>>graph1,graph2;
vector<int>dp;
vector<int>vis;

bool loop;

void tdfs(int x)
{
    vis[x]=1;
    for(auto c:graph1[x])
    {
        if(vis[c])
        {
            if(vis[c]==1) {loop = true;}
            continue;
        }
        tdfs(c);
    }
    vis[x]=2;
}

int dfs(int x)
{
    if(dp[x]!=-1) return dp[x];
    int cnt = 0;
    for(auto c : graph2[x])
    {
        if(c<x) cnt = max(cnt,dfs(c)-1);
        else cnt=max(cnt,dfs(c));
    }
    return dp[x]=cnt+1;
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
        graph1.assign(n+1,vector<int>());
        graph2.assign(n+1,vector<int>());
        dp.assign(n+1,-1);
        vis.assign(n+1,0);
        loop = false;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            for(int j=0;j<a;j++)
            {
                int b;
                cin>>b;
                graph1[b].pb(i);
                graph2[i].pb(b);
            }
        }
        //cout<<graph2[3].size()<<endl;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) tdfs(i);
        }
        if(loop)
        {
            cout<<"-1\n";
            continue;
        }
        int mx = 0;
        for(int i=1;i<=n;i++)
        {
            mx = max(mx,dfs(i));
            //cout<<i<<" "<<mx<<endl;
        }
        cout<<mx<<endl;
        //YES;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
