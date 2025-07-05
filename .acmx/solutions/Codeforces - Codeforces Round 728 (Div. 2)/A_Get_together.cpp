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

vector<pair<int,int>>vec;

bool abc(long double x)
{
    long double ln = -1e14, rn = 1e14;
    for(int i=0;i<vec.size();i++)
    {
        ln = max(ln,vec[i].first-vec[i].second*x);
        rn = min(rn,vec[i].first+vec[i].second*x);
    }
    return rn>=ln;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            vec.pb({a,b});
        }
        long double lo = 0, hi = 1;
        while(!abc(hi)) hi*=2;
        for(int i=0;i<100;i++)
        {
            long double mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid;
        }
        if(abc(lo)) cout<<setprecision(20)<<lo<<endl;
        else cout<<setprecision(20)<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
