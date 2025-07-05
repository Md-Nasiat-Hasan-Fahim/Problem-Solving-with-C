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
vector<int>prime;
int ara[300005];

void sieve()
{
    prime.pb(2);
    for(int i=3;i*i<300005;i+=2)
    {
        if(!ara[i])
        {
            prime.pb(i);
            for(int j=i*i;j<300005;j+=i+i) ara[j]=1;
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    sieve();
    cout<<prime.size()<<endl;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;char a;
        cin>>n>>a;
        string s;
        cin>>s;
        vector<int>vec;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='a') vec.pb(i+1);
        }

    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
