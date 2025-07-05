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
const int inf = 1e16;
const int mx = 100005;

vector<pair<int,int>>graph[mx];
int dis[mx];
bool vis[mx];

void disj()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int fv = pq.top().first;
        int f = pq.top().second;
        pq.pop();
        if(vis[f]) continue;
        vis[f]=true;
        for(auto c : graph[f])
        {
            if(dis[f]+c.second<dis[c.first])
            {
                dis[c.first]=dis[f]+c.second;
                pq.push({dis[c.first],c.first});
            }
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(vis,false,sizeof(vis));
        for(int i=0;i<mx;i++) dis[i]=inf;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int a,b,v;
            cin>>a>>b>>v;
            graph[a].pb({b,v});
        }
        disj();
        for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
