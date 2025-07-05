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

vector<vector<int>>dp;
vector<int>graph[200005];
int n,k;

long long POW(long long n, long long r)
{
    if(r==0) return 1LL;
    long long res = POW(n,r/2);
    res = 1LL*res*res;
    res%=mod;
    if(r%2LL==1LL) res = 1LL*n*res;
    res%=mod;
    return res;
}

void dfs(int x, int p)
{
    for(auto c:graph[x])
    {
        if(c==p) continue;
        dfs(c,x);
        for(int i=1;i<=k;i++)
        {
            dp[x][i]+=(dp[c][i-1]!=0)+dp[c][i];
            dp[x][i]%=mod;
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>k;
        dp.assign(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++) dp[i][1]=1;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        dfs(1,1);
        int cq = (n*(n-1))/2;
        cout<<cq<<endl;
        cq = POW(cq,mod-2);
        cout<<dp[1][k]<<endl;
        int ans = dp[1][k]*cq;
        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
