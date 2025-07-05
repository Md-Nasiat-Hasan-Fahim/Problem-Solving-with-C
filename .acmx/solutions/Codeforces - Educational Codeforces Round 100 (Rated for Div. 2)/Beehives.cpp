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
int dis[501];
vector<vector<int>>graph;
int mn;
int d;

void dfs(int s, int p)
{
   // cout<<s<<" "<<dis[s]<<endl;
    for(int &c : graph[s])
    {
        if(c==p) continue;
        if(!dis[c])
        {
            dis[c]=1+dis[s];
            dfs(c,s);
        }
        else if(dis[s]>dis[c])
        {
            cout<<s<<" "<<c<<endl;
            mn = min(mn,dis[s]-dis[c]+1);
        }
    }
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        memset(dis,0,sizeof(dis));
        int n,m;
        cin>>n>>m;
        mn = INT_MAX;
        d=0;
        graph.assign(n+2,vector<int>());
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        for(int i=0;i<n;i++)
        {
            if(!dis[i])
            {
                dis[i]=1;
                dfs(i,i);
            }
        }
        //for(int i=0;i<n;i++)
        //cout<<i<<" "<<dis[i]<<endl;
        if(mn!=INT_MAX)
        cout<<mn<<endl;
        else cout<<"impossible\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
