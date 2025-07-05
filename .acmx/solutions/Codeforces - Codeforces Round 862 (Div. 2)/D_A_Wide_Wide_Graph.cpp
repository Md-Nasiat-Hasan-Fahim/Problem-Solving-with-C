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
vector<int> par;
vector<vector<int>>lev;
int n;
int tme;
vector<int>start,finish;
vector<vector<int>>graph;

int dsu(int r)
{
    if(par[r]==r) return r;
    return par[r]=dsu(par[r]);
}

int abc(int x,int mxl)
{
    par.clear();
    for(int i=0;i<=n;i++) par.push_back(i);
    for(int i=0;i+x<=mxl;i++)
    {
        for(int j=0;j<lev[i].size();j++)
        {
            for(int k=0;k<lev[i+x].size();k++)
            {
                int a = dsu(lev[i][j]);
                int b = dsu(lev[i+x][k]);
                if((start[lev[i][j]]<start[lev[i+x][k]]&&finish[lev[i+x][k]]<finish[lev[i][j]]))
                {
                    if(a!=b)par[lev[i+x][k]]=a;
                }
            }
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++) {st.insert(par[i]);cout<<i<<" "<<start[i]<<" "<<finish[i]<<" "<<par[i]<<endl;}
    return st.size();
}

void dfs(int x,int p)
{
    start[x]=++tme;
    for(auto c: graph[x])
    {
        if(c==p) continue;
        dfs(c,x);
    }
    finish[x]=++tme;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    //cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        cin>>n;
        graph.assign(n+1,vector<int>());
        start.assign(n+1,0),finish.assign(n+1,0);
        tme=0;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vector<int>level(n+1,-1);
        //bfs
        level[1]=0;
        queue<int>q;
        q.push(1);
        int mxl = 0,cur=1;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(auto c:graph[p])
            {
                if(level[c]!=-1) continue;
                level[c]=level[p]+1;
                q.push(c);
                if(level[c]>mxl)
                {
                    mxl=level[c];
                    cur = c;
                }
            }
        }
        dfs(cur,cur);
        fill(all(level),-1);
        q.push(cur);
        mxl = 0;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(auto c:graph[p])
            {
                if(level[c]!=-1) continue;
                level[c]=level[p]+1;
                q.push(c);
                mxl = max(mxl,level[c]);
            }
        }
        lev.assign(mxl+1,vector<int>());
        for(int i=1;i<=n;i++)
        {
            lev[level[i]].pb(i);
        }
        abc(1,mxl);
        /*int i=1;
        for(;i<=mxl;i++)
        {
            cout<<abc(i,mxl)<<" ";
        }
        for(;i<=n;i++)
        cout<<n<<" ";
        cout<<endl;*/
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
