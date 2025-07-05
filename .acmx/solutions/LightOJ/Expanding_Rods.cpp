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

long double s,l;

bool abc(long double a)
{
    long double th,r;
    r = sqrtl((a*a)+((l*l)/4));
    th = 2*asinl(l/(2*r));
    return r*th>=s;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        long double n,c;
        cin>>l>>n>>c;
        s = (1+(n*c))*l;
        long double lo = 0.1, hi = 1;
        while(abc(hi)) hi*=2;
        for(int i=0;i<100;i++)
        {
            long double mid = (hi+lo)/2.0;
            if(abc(mid))lo = mid;
            else hi = mid;
        }
        long double r = sqrtl((lo*lo)+((l*l)/4));
        cout<<setprecision(15)<<r-lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
