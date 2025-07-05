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
const int mx = 2e5+5;
int fact[mx];
int inv[mx];

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

void cal()
{
    fact[0]=1;
    for(int i=1;i<mx;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
        if(fact[i]<0) fact[i]+=mod;
    }
    inv[mx-1]=POW(fact[mx-1],mod-2);
    for(int i=mx-2;i>-1;i--)
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
    cnt=cnt*inv[n-r];
    cnt%=mod;
    if(cnt<0) cnt+=mod;
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    cal();
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        //cout<<"Case "<<z<<": ";
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int c = upper_bound(all(vec),vec[i]+k)-vec.begin()-i;
            if(c-1>=m-1) ans+=ncr(c-1,m-1);
            ans%=mod;
            if(ans<0) ans+=mod;
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
