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
const int mx_lim = 

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
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        //cout<<"Case "<<z<<": ";
        /*int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];*/
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
