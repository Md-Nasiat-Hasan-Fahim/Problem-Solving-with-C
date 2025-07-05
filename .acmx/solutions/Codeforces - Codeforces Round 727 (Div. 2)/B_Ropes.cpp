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

int n,k;
vector<double>vec;

bool abc(double x)
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        cnt+=(vec[i]/x);
    }
    return cnt>=k;
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
        cin>>n>>k;
        vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        double lo = 0, hi = 1e7+5;
        for(int i=0;i<100;i++)
        {
            double mid = (hi+lo)/2.0;
            if(abc(mid)) lo = mid;
            else hi = mid;
        }
        if(abc(hi)) cout<<setprecision(15)<<hi<<endl;
        else cout<<setprecision(15)<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
