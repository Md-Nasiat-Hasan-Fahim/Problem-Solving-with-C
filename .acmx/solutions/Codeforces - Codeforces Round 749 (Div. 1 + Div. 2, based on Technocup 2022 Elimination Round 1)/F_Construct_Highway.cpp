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

vector<int>par;
vector<int>vis;
vector<vector<int>>graph;
vector<int>deg;
priority_queue<pair<int,int>>gol;


int dsu(int r)
{
    if(par[r]==r) return r;
    return par[r]=dsu(par[r]);
}

void dfs(int x)
{
    vis[x]=true;
    for(auto c:graph[x])
    {
        if(!vis[c]) dfs(c);
    }
    gol.push({deg[x],x});
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,m;
        cin>>n>>m;
        graph.assign(n+1,vector<int>());
        for(int i=0;i<=n;i++) par.pb(i);
        deg.assign(n+1,0);
        for(int i=1;i<=n;i++) cin>>deg[i];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            int u = dsu(a);
            int v = dsu(b);
            if(u!=v)
            {
                par[v]=par[u];
            }
            graph[a].pb(b);
            graph[b].pb(a);
            deg[a]--;
            deg[b]--;
        }
        int par1 = dsu(1);
        vis.assign(n+1,0);
        vis[1]=true;
        gol.push({deg[1],1});
        queue<pair<int,int>>pr;
        for(int i=2;i<=n;i++)
        {
            int tpr = dsu(i);
            if(par1==tpr)
            {
                dfs(i);
            }
        }
        int cnt = 0;
        priority_queue<pair<int,int>>pq;
        vector<int>vec;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                pq.push({deg[i],i});
            }
        }
        while(!pq.empty())
        {
            vec.pb(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<vec.size()&&gol.size();i++)
        {
            if(vis[vec[i]]) continue;
            int pri = dsu(vec[i]);
            int par1 = 1;
            auto [ga,a]=gol.top();
            gol.pop();
           // cout<<a<<" "<<vec[i]<<" -- "<<par1<<" "<<pri<<endl;
            if(pri!=par1)
            {
                par[pri]=par[par1];
                deg[a]--;
                deg[vec[i]]--;
                dfs(vec[i]);
                pr.push({a,vec[i]});
                if(deg[a])gol.push({deg[a],a});
                if(deg[a])gol.push({deg[vec[i]],vec[i]});
                //cout<<deg[qu[cnt]]<<" "<<deg[i]<<endl;
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<deg[i]<<endl;
            if(deg[i]>0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            while(!pr.empty())
            {
                cout<<pr.front().first<<" "<<pr.front().second<<endl;
                pr.pop();
            }
        }
        else cout<<"-1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}