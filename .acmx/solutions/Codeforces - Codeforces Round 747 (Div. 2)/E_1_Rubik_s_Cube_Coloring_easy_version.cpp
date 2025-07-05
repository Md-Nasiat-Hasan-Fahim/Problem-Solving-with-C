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

int POW(int n, int r)
{
    if(r==0)
    return 1;
    int res = POW(n,r/2);
    res=(res*res)%mod;
    if(r%2==1) res*=n;
    res%=mod;
    return res;
}

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int r = (1LL<<n)-2;
        //cout<<r<<endl;
        int cnt = POW(4,r);
        cnt*=6;
        cnt%=mod;
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
