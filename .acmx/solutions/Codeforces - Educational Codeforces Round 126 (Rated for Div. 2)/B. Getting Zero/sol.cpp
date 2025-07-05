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
const int mod = 32768;
int dp[mod+5];
int vis[mod+5];

int abc(int n)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    if(vis[n]==-1) return INT_MAX;
    vis[n]=-1;
    int cnt = min(abc((2*n)%mod),abc((n+1)%mod))+1;
    vis[n]=1;
    dp[n]=cnt;
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    memset(dp,-1,sizeof(dp));
    cout<<abc(1035)<<endl;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {

    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
