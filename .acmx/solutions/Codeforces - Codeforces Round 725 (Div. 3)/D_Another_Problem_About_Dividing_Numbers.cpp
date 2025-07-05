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
const int mx = 1e5+5;
vector<int>prime;
int ara[mx];

void sieve()
{
    prime.pb(2);
    for(int i=3;i*i<mx;i+=2)
    {
        if(!ara[i])
        {
            for(int j=i*i;j<mx;j+=i+i)
            {
                ara[j]=1;
            }
        }
    }
    for(int i=3;i<mx;i+=2) if(!ara[i]) prime.pb(i);
}

int fact(int a)
{
    int cnt = 0;
    for(int i=0;i<prime.size()&&a>1;i++)
    {
        if(a%prime[i]==0) {while(a%prime[i]==0) {a/=prime[i];cnt++;}}
    }
    if(a>1) cnt++;
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    sieve();
    for(int z=1;z<=t;z++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int x = fact(a);
        int y = fact(b);
        if(a==b)
        {
            if(k>=0&&k<=x+y&&k!=1) YES;
            else NO;
        }
        else if(a%b==0||b%a==0)
        {
            if(k>=1&&k<=x+y) YES;
            else NO;
        }
        else
        {
            if(k>=2&&k<=x+y) YES;
            else NO;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}