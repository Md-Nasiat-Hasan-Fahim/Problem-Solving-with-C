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
vector<int>pos,blocked;

int dfs(int x, int f,int level)
{
    int ct = INT_MAX;
    for(auto c:graph[x])
    {
        if(c==f) continue;
        if(pos[c])
        {
            blocked[x]=1;
            //cout<<x<<" "<<"1\n";
            return 2;
        }
        int y = dfs(c,x,level+1);
        ct = min(y,ct);
        if(y<=level)
        {
            //cout<<x<<" "<<y<<" "<<level<<endl;
            blocked[x]=1;
        }
    }
    return ct+1;
}

bool ans;

void dfs2(int x, int f)
{
    for(auto c:graph[x])
    {
        //cout<<blocked[c]<<" "<<x<<" "<<f<<endl;
        if(c==f||blocked[c]) continue;
        dfs2(c,x);
    }
    
    if(graph[x].size()==1&&x!=1) ans = true;
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
        int n,k;
        cin>>n>>k;
        ans = false;
        graph.assign(n+1,vector<int>());
        pos.assign(n+1,0);
        blocked.assign(n+1,0);
        for(int i=1;i<=k;i++)
        {
            int a;
            cin>>a;
            pos[a]=i;
            blocked[a]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1,1,0);
        //cout<<blocked[7]<<endl;
        dfs2(1,1);
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
