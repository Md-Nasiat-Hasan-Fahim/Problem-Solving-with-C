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

long long POW(long long n, long long r)
{
    if(r==0) return 1LL;
    long long res = POW(n,r/2);
    res = ((__int128)1*res*res)%mod;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2LL==1LL) res = ((__int128)1*n*res)%mod;
    res%=mod;
    if(res<0) res+=mod;
    return res;
}

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n,k;
        cin>>n>>k;
        int ans = 0;
        if(1)
        {
            int cnt;
            if(n%2)cnt=POW(2,n-1)+1;
            else cnt=POW(2,n-1)-1;
            ans = POW(cnt,k);
        }
        else
        {
            int cnt = 0;
            cnt = POW(2,n-1)-1;
            ans = POW(cnt,k);
            cout<<ans<<endl;
            for(int i=1;i<=k;i++)
            {
                int x  = POW(2,n*(k-i))*POW(2,i-1);
                x%=mod;
                if(x<0) x+=mod;
                ans+=x;
                ans%=mod;
                if(ans<0) ans+=mod;
            }
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
