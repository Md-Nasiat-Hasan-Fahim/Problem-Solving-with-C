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
int mod;

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

int fact[250005];

void factorial()
{
    fact[0]=1;
    for(int i=1;i<250005;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
        if(fact[i]<0) fact[i]+=mod;
    }
}

int mul(int x, int y)
{
    int cnt = x*y;
    cnt%=mod;
    if(cnt<0) cnt+=mod;
    return cnt;
}


signed main()
{
    int n;
    cin>>n>>mod;
    factorial();
    int cnt = 0;                                                
    return 0;
}
