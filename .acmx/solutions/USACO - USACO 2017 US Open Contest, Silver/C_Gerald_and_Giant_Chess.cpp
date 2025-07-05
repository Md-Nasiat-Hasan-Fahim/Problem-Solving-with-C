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
const int mx_lim = 2e5;
//please define mx_lim as "const int mx_lim = value;"
//fact[] is what contain factorial of a number%mod
//inv[i] contains modular inverse of fact[i] or i!
//you have to call function factorial before inverse
int fact[mx_lim];
int inv[mx_lim];

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

void factorial()
{
    fact[0]=1;
    for(int i=1;i<mx_lim;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
        if(fact[i]<0) fact[i]+=mod;
    }
}

void modulo_inverse()
{
    inv[mx_lim-1]=POW(fact[mx_lim-1],mod-2);
    for(int i=mx_lim-2;i>-1;i--)
    {
        inv[i]=(i+1)*inv[i+1];
        inv[i]%=mod;
        if(inv[i]<0) inv[i]+=mod;
    }
}

int ncr(int n, int r)
{
    int cnt = fact[n]*inv[r];
    cnt%=mod;
    if(cnt<0) cnt+=mod;
    if(n>=r) cnt=cnt*inv[n-r];
    else cnt=0;
    cnt%=mod;
    if(cnt<0) cnt+=mod;
    return cnt;
}
signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    factorial();
    modulo_inverse();
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int a,b,n;
        cin>>a>>b>>n;
        vector<pair<int,int>>vec;
        vec.pb({1,1});
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            vec.pb({x,y});
        }
        vec.pb({a,b});
        int dp[n+5];
        sort(all(vec));
        for(int i=1;i<n+2;i++)
        {
            dp[i]=ncr((vec[i].first-1+vec[i].second-1),(vec[i].first-1));
            for(int j=1;j<n+1;j++)
            {
                if(i==j) continue;
                if(vec[j].first<=vec[i].first&&vec[j].second<=vec[i].second)
                {
                    int x = ((__int128)1)*dp[j]*(ncr(vec[i].first-vec[j].first+vec[i].second-vec[j].second,vec[i].first-vec[j].first))%mod;
                    x%=mod;
                    if(x<0) x+=mod;
                    dp[i]-=x;
                    dp[i]%=mod;
                    if(dp[i]<0) dp[i]+=mod;
                }
            }
        }
        cout<<dp[n+1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
