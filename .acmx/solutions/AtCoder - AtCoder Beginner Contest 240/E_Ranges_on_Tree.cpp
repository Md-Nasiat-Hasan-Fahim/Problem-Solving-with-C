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

vector<pair<int,int>>vec;
vector<vector<int>>graph;

int dfs(int x, int p, int cnt)
{
    int ct = cnt;
    int i = 0;
    for(auto c:graph[x])
    {
        if(c==p) continue;
        ct=dfs(c,x,ct+(i>0));
        i++;
    }
    vec[x]={cnt,ct};
    return ct;
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
        int n;cin>>n;
        vec.assign(n+1,pair<int,int>());
        graph.assign(n+1,vector<int>());
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1,1,1);
        for(int i=1;i<=n;i++) cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
