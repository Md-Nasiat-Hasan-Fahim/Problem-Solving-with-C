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
const int inf = -1e18;

struct node
{
    int a,b,v;
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>dis(n+1,inf);
        dis[1]=0;
        vector<node>vec;
        for(int i=0;i<m;i++)
        {
            int a,b,v;
            cin>>a>>b>>v;
            vec.pb({a,b,v});
        }
        int x;
        for(int i=0;i<n;i++)
        {
            x=-1;
            for(auto c:vec)
            {
                if(dis[c.b]<dis[c.a]+c.v)
                {
                    dis[c.b]=dis[c.a]+c.v;
                    x=1;
                }
            }
        }
        if(x==1)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<dis[n]<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
