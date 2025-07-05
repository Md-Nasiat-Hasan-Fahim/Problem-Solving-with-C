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
vector<int>leaf;
vector<pair<int,int>>pr;
void reset()
{
    for(int i=0;i<graph.size();i++)
    {
        graph[i].clear();
    }
    leaf.clear();
    pr.clear();
}

int dfs(int x, int p)
{
    int cnt = INT_MAX;
    for(auto c:graph[x])
    {
        if(c==p) continue;
        int less = dfs(c,x);
        cnt = min(less,cnt);
        if(less==2) pr.pb({c,x});
    }
    if(cnt==INT_MAX) {leaf.pb(x);return 1;}
    cnt++;
    return cnt;
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
        reset();
        int n;
        cin>>n;
        graph.assign(n+1,vector<int>());
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        dfs(1,1);
        int sz[n+1]={0};
        for(int i=1;i<=n;i++) sz[i]=graph[i].size();
        int cnt = leaf.size();
        for(auto [c,p]:pr)
        {
            cout<<c<<" "<<p<<endl;
            if(sz[p]>2&&leaf.size()||(p==1&&sz[p]>1&&leaf.size()))
            {
                sz[p]--;
                leaf.pop_back();
                cnt--;
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
