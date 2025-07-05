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
vector<int>disa,disb,vis,mark;

void bfs(int s, vector<int> &dis)
{
    queue<int>q;
    q.push(s);
    dis[s]=0;
    vis[s]=true;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(auto c:graph[f])
        {
            if(vis[c]) continue;
            dis[c]=dis[f]+1;
            vis[c]=true;
            q.push(c);
        }
    }
}

int dfs(int x,int p)
{
    vis[x]=true;
    int yz = -1;
    for(auto c:graph[x])
    {
        if(c==p) continue;
        if(vis[c])
        {
            yz = c;
        }
        else
        {
            yz = dfs(c,x);
        }
        if(yz!=-1) break;
    }
    if(yz!=-1)
    {
        mark[x]=yz;
        if(yz==x) return -1;
        else return yz;
    }
    return -1;
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
        int n,a,b;
        cin>>n>>a>>b;
        swap(a,b);
        graph.assign(n+1,vector<int>());
        disa.assign(n+1,0);
        disb.assign(n+1,0);
        vis.assign(n+1,0);
        mark.assign(n+1,-1);
        for(int i=0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[v].pb(u);
            graph[u].pb(v);
        }
        dfs(1,1);
        vis.assign(n+1,0);
        bfs(a,disa);
        vis.assign(n+1,0);
        bfs(b,disb);
        if(a==b)
        {
            NO;
            continue;
        }
        if(mark[a]!=-1)
        {
            YES;
            //cout<<mark[a]<<endl;
            continue;
        }
        int mx = LONG_LONG_MAX;
        int pt = -1;
        for(int i=1;i<=n;i++)
        {
            if(i==a) continue;
            if(disa[i]<mx&&mark[i]!=-1)
            {
                mx=disa[i];
                pt = i;
            }
        }
        if(disb[pt]>disa[pt]) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
