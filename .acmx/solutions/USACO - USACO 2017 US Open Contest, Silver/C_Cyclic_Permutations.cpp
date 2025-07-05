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
const int mx_lim = 1e6+5;

int fact[mx_lim];

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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    factorial();
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int ans = fact[n]-POW(2,n-1);
        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
