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
struct node
{
    int w,u,v;
};

vector<int>par;

int find_par(int x)
{
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        int n;
        cin>>n;
        vector<node>ed;
        par.assign(n+1,0);
        for(int i=1;i<=n;i++) par[i]=i;
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int a;
                cin>>a;
                if(a)
                ed.pb({a,i,j});
                sum+=a;
            }
        }
        sort(all(ed),[](node a, node b)
        {
            return a.w<b.w;
        });
        int cnt = 0;
        int mst = 0;
        for(int i=0;i<ed.size();i++)
        {
            if(ed[i].u==ed[i].v) continue;
            int a = find_par(ed[i].u);
            int b = find_par(ed[i].v);
            if(a!=b)
            {
                cnt++;
                mst+=ed[i].w;
                par[a]=b;
            }
        }
        if(cnt==n-1) cout<<sum-mst<<endl;
        else cout<<"-1\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
