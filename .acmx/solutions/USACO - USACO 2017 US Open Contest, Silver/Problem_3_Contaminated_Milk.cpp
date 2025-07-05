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



signed main()
{
    freopen("badmilk.in","r+",stdin);
    freopen("badmilk.out","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m,d,s;
        cin>>n>>m>>d>>s;
        vector<vector<int>>tim(n+1,vector<int>(m+1,mod));
        vector<int>vec[m+1];
        int dis[n+1];
        memset(dis,-1,sizeof(dis));
        for(int i=0;i<d;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            vec[b].pb(a);
            tim[a][b]=min(c,tim[a][b]);
        }
        for(int i=0;i<s;i++)
        {
            int a,b;
            cin>>a>>b;
            dis[a]=b;
        }
        queue<int>q;
        for(int i=1;i<=m;i++)
        {
            bool ans = false;
            for(int j=1;j<=n;j++)
            {
                if(dis[j]!=-1&&dis[j]<=tim[j][i])
                {
                    ans=false;
                    break;
                }
                else if(dis[j]!=-1&&dis[j]>tim[j][i]) ans = true;
            }
            if(ans) q.push(i);
        }
        int ans = -1;
        while(!q.empty())
        {
            ans = max(ans,1LL*vec[q.front()].size());
            q.pop();
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
