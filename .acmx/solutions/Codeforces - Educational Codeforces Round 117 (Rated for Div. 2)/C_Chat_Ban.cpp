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

int k,x;

bool abc(int y)
{
    int p;
    if(y<=k) p = ((__int128_t)y*(y+1))/2;
    else 
    {
        p = ((__int128_t)k*(k+1))/2;
        int xy = y-k;
        int a = k - xy;
        int n = (k-1)-a+1;
        p+=(n*(a+k-1))/2;
    }
    return p<x;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>k>>x;
        int lo = 0, hi = 2*k-1;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid;
        }
        //cout<<hi<<" "<<lo<<endl;
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo+1<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
