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
const int mod =  998244353;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,k;
        cin>>n>>k;
        int dp[n+1][k+1];
        int cum[n+1][k+1];
        memset(dp,0,sizeof(dp));
        memset(cum,0,sizeof(cum));
        for(int i=1;i<=k;i++) dp[2][i]=1,cum[2][i]=cum[2][i-1]+cum[1][i]-cum[1][i-1]+dp[2][i];
        for(int i=0;i<=n;i++) dp[i][1]=1,cum[i][1]=cum[i-1][1]+cum[i][0]+dp[i][1];
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=cum[n][k]-cum[n-1][k-1];
                cum[i][j]=dp[i][j]+cum[n-1][k]+cum[n][k-1]-cum[n-1][k-1];
            }
        }
        cout<<cum[3][1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
