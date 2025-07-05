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
const int MAX = 50005;

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

int ara[MAX];
vector<int>prime;

void sieve()
{
    prime.pb(2);
    for(int i=3;i*i<MAX;i+=2)
    {
        if(ara[i]==0)
        {
            prime.pb(i);
            for(int j=i*i;j<MAX;j+=i+i)
            {
                ara[j]=1;
            }
        }
    }
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    sieve();
    while(t--)
    {
        int n;
        cin>>n;
        int one = 1;
        for(int i=0;i<prime.size()&&prime[i]<=n;i++)
        {
            int cnt = 0;
            for(int j = prime[i]; j<=n;j*=prime[i])
            {
                cnt+=(n/j);
                cnt%=mod;
            }
            one*=(cnt+1);
            one%=mod;
        }
        cout<<one<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
