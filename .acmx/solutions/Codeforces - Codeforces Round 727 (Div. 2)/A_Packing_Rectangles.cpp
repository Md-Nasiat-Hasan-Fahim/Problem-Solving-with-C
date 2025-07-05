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
int w,h,n;

bool abc(int x)
{
    int a = x/w;
    int b = x/h;
    return a*b>=n;
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
        cin>>w>>h>>n;
        int l = 0, r = 1;
        while(!abc(r)) r*=2;
        while(r-l>1)
        {
            int mid = (r+l)/2;
            if(abc(mid)) r = mid;
            else l = mid+1;
        }
        if(abc(l)) cout<<l<<endl;
        else cout<<r<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
