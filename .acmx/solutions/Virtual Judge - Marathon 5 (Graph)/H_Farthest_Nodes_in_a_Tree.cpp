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
int n;
vector<vector<pair<int,int>>>graph;

int bfs(int s,vector<int>&dis)
{
    vector<int>vis(n+1);
    dis[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(auto [ca,cw]:graph[f])
        {
            if(!vis[ca])
            {
                //cout<<ca<<" "<<f<<endl;
                vis[ca]=1;
                dis[ca]=dis[f]+cw;
                q.push(ca);
            }
        }
    }
    int mx = -1,mxid=-1;
    for(int i=0;i<n;i++)
    {
        if(dis[i]>mx)mx=dis[i],mxid=i;
    }
    return mxid;
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
        cin>>n;
        graph.assign(n+1,vector<pair<int,int>>());
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].pb({v,w});
            graph[v].pb({u,w});
        }
        vector<int>dis(n+1);
        int a = bfs(0,dis);
        //cout<<a<<endl;
        dis.assign(n+1,0);
        cout<<"Case "<<tttttttt<<": ";
        cout<<dis[bfs(a,dis)]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
