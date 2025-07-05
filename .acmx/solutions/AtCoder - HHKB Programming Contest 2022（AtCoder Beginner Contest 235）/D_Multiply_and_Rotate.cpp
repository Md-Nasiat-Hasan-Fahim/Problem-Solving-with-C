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

bool ans;
int a,n,nd;

int abc(int x, int cnt , int digit)
{
    int pqr = INT_MAX;
    if(cnt>6||digit>nd)
    {
        if(cnt==n) return 0;
        return INT_MAX;
    }
    if(x>10&&x%10!=0)
    {
        int y = x%10;
        x/=10;
        pqr = abc(y*POW(digit,10)+x,cnt+1,digit);
    }
    int ct = 0;
    int m = x*a;
    while(m)
    {
        m/=10;
        ct++;
    }
    pqr = min(pqr,abc(x*a,0,ct));
    return 1+pqr;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
   // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        ans = false;
        cin>>a>>n;
        nd = 0;
        int m = n;
        while(m)
        {
            m/=10;
            nd++;
        }
        int ct = abc(1,0,1);
        if(ct>=INT_MAX) cout<<"-1"<<endl;
        else cout<<ct<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
