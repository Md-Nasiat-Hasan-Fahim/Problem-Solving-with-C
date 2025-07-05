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
const int mx = 3e5+7;
int fact[mx];
int rev[mx];

int POW(int n, int r)
{
    if(r==0) return 1;
    int res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(r%2==1) res = res*n;
    res%=mod;
    return res;
}

int ncr(int n, int r)
{
    int cnt = fact[n]*rev[r];
    cnt%=mod;
    cnt*=rev[n-r];
    cnt%=mod;
    return cnt%mod;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    fact[0]=1;
    for(int i=1;i<mx;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    rev[mx-1]=POW(fact[mx-1],mod-2);
    for(int i=mx-2;i>-1;i--)
    {
        rev[i]=(i+1)*rev[i+1];
        rev[i]%=mod;
    }
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int cnt = ncr(n/3,n/6);
        for(int i=0;i<n/3;i++)
        {
            int x1,x2,x3;
            cin>>x1>>x2>>x3;
            if(x1==x2&&x2==x3)
            {
                cnt*=3;
            }
            else if((x1==x2&&x3>x2)||(x2==x3&&x1>x2)||(x3==x1&&x2>x3))
            {
                cnt*=2;
            }
            cnt%=mod;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
