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

int dp[201][21][21][11];
vector<int>vec;

int abc(int i, int rem, int d, int m)
{
    if(m==0)
    {
        return rem==0;
    }
    if(i==vec.size()) return 0;
    int &x = dp[i][rem][d][m];
    if(x!=-1) return x;
    int cnt =0;
    int p = (rem+vec[i])%d;
    //if(p<0)x+=d;
    cnt+=abc(i+1,p,d,m-1LL);
    cnt+=abc(i+1,rem,d,m);
    return x=cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(dp,-1,sizeof(dp));
        vec.clear();
        cout<<"Case "<<z<<":\n";
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec.pb(a);
        }
        while(q--)
        {
            int d,m;
            cin>>d>>m;
            cout<<abc(0,0,d,m)<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
