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

int dsu(int r, vector<int>& par)
{
    if(par[r]==r) return r;
    return par[r]=dsu(par[r],par);
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
        vector<int>par1,par2;
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i<n+2;i++)
        {
            par1.pb(i);
            par2.pb(i);
        }
        for(int i=0;i<a;i++)
        {
            int x,y;
            cin>>x>>y;
            int px = dsu(x,par1);
            int py = dsu(y,par1);
            if(px!=py) par1[py]=dsu(x,par1);
        }
        for(int i=0;i<b;i++)
        {
            int x,y;
            cin>>x>>y;
            int px = dsu(x,par2);
            int py = dsu(y,par2);
            if(px!=py)
            par2[py]=dsu(x,par2);
        }
        queue<pair<int,int>>pr;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                int p1i = dsu(i,par1);
                int p1j = dsu(j,par1);
                int p2i = dsu(i,par2);
                int p2j = dsu(j,par2);
                if(p1i!=p1j&&p2i!=p2j)
                {
                    pr.push({i,j});
                    par1[p1j]=dsu(i,par1);
                    par2[p2j]=dsu(i,par2);
                }
            }
        }
        cout<<pr.size()<<endl;
        while(!pr.empty())
        {
            cout<<pr.front().first<<" "<<pr.front().second<<endl;
            pr.pop();
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
