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

const int ncr_size = 1e4;

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
}


int fact[ncr_size+2],inv[ncr_size+2];

void ncr_calcultion()
{
    fact[0]=1;fact[1]=1;
    for(int i=2;i<ncr_size;i++) fact[i]=(fact[i-1]*i),fact[i]%=mod;
    inv[ncr_size-1]=POW(fact[ncr_size-1],mod-2);
    for(int i=ncr_size-2;i>-1;i--) inv[i]=inv[i+1]*(i+1),inv[i]%=mod;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {

    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
