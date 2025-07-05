#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int par[n+1];
        vector<int>vec[n+1];
        for(int i=0;i<n;i++)
        cin>>par[i];
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec[par[i]].pb(a);
        }
        int mx = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            sort(rall(vec[i]));
            int mn = vec[i].size();
            mx = max(mx,mn);
            for(int j=1;j<mn;j++)
            vec[i][j]+=vec[i][j-1];
        }
        int i;
        for(i=1;i<=min(mx,n);i++)
        {
            int cnt = 0;
            for(int j=1;j<=n;j++)
            {
                if(vec[j].size()>=i)
                {
                    cnt+=vec[j][(vec[j].size()/i)*i-1];
                }
            }
            cout<<cnt<<" ";
        }
        for(;i<=n;i++)
        cout<<"0 ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
