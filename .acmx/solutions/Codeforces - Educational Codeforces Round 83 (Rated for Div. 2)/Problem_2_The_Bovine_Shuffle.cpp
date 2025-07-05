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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
   // cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int ara[n+1];
        int ans[n+1];
        //cout<<"skjfd";
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            ara[i]=a;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>ans[ara[j]];
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
        //dcout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
