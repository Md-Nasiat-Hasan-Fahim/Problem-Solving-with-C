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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        int n,m;
        cin>>n>>m;
        vector<int>graph[n];
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            queue<int>q;
            vector<int>par(n+1,-1);
            vector<int>dis(n+1,INT_MAX);
            q.push(i);
            dis[i]=0;
            while(!q.empty())
            {
                int f = q.front();
                q.pop();
                for(auto c: graph[f])
                {
                    if(dis[c]==INT_MAX)
                    {
                        dis[c]=1+dis[f];
                        par[c]=f;
                        q.push(c);
                    }
                    else if(par[c]!=f&&par[f]!=c)
                    {
                        ans = min(ans,dis[f]+dis[c]+1);
                    }
                }
            }
        }
        if(ans!=INT_MAX)
        cout<<ans<<endl;
        else cout<<"impossible\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
