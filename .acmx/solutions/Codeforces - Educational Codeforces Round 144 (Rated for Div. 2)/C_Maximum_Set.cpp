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
const int mod = 998244353;

long long POW(long long n, long long r)
{
    if(r==0) return 1LL;
    long long res = POW(n,r/2);
    res = 1LL*res*res;
    if(r%2LL==1LL) res = 1LL*n*res;
    return res;
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
        int l,r;
        cin>>l>>r;
        int x = r/l;
        int lim = log2(x);
        int ans = 0;
        int i3 = r/(3*POW(2,lim-1));
        i3 = max(i3-l+1,0LL);
        i3*=lim;
        i3%=mod;
        if(i3<0) i3+=mod;
        int i4 = r/POW(2,lim);
        i4 = max(i4-l+1,0LL);
        ans+=i3;
        ans%=mod;
        if(ans<0) ans+=mod;
        ans+=i4;
        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<lim+1<<" "<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
