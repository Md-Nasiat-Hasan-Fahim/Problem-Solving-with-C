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
const int mx = 505;
int graph[mx][mx];

void fw(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                graph[i][j]=graph[i][k]+graph[k][j];
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
        for(int i=0;i<mx;i++)
        for(int j=0;j<mx;j++)
        {
            if(i==j) graph[i][j]=0;
            else graph[i][j]=inf;
        }
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=0;i<m;i++)
        {
            int a,b,v;
            cin>>a>>b>>v;
            graph[a][b]=min(graph[a][b],v);
            graph[b][a]=min(graph[b][a],v);
        }
        fw(n);
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            if(graph[a][b]!=inf) cout<<graph[a][b]<<endl;
            else cout<<"-1\n";
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}