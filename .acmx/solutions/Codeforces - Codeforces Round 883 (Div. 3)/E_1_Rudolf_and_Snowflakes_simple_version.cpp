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
const int mod = LONG_LONG_MAX;
const int mx = 1e18+10;

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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    vector<int>vec;
    for(int i=2;i<=1000000;i++)
    {
        for(int j=i*i+i+1,k=i*i;j<mx;)
        {
            // if(i==3) cout<<j<<endl;
            vec.pb(j);
            if((__int128_t)k*i>mx) break;
            k*=i;
            if((__int128_t)j+k>mx) break;
            j+=k;
        }
    }
    sort(all(vec));
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        if(binary_search(all(vec),n)) YES;
        else NO;
        cout<<vec.back()<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
