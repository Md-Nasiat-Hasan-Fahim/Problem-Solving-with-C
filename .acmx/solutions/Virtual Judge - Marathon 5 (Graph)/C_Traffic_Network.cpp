#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

void dij(int s,int b,vector<vector<pair<int,int>>>&vec,vector<int>&dis)
{
    dis[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,s});
    vector<int>vis(dis.size());
    while(!pq.empty())
    {
        auto [fw,fa] = pq.top();
        vis[fa]=1;
        if(fa==b) return;
        pq.pop();
        for(auto [cw,ca]:vec[fa])
        {
            if(!vis[ca]&&dis[ca]>fw+cw)
            {
                //cout<<fa<<" "<<ca<<" "<<cw<<endl;
                dis[ca] = fw + cw;
                pq.push({dis[ca],ca});
            }
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
        int n,m,k,s,t;
        cin>>n>>m>>k>>s>>t;
        vector<vector<pair<int,int>>>vec(n+1,vector<pair<int,int>>());
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            //cout<<i<<endl;
            cin>>u>>v>>w;
            vec[u].pb({w,v});
        }
        int mn = INT_MAX;
        while(k--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vec[u].pb({w,v});
            vec[v].pb({w,u});
            vector<int>dis(n+1,INT_MAX);
            dij(s,t,vec,dis);
            //cout<<dis[t]<<endl;
            mn = min(mn,dis[t]);
            vec[u].pop_back();
            vec[v].pop_back();
        }
        if(mn==INT_MAX) mn = -1;
        cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
