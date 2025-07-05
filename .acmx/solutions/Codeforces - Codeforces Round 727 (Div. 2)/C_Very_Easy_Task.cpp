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

int n,x,y;

bool abc(int a)
{
    return ((a/x)+(a/y))>=n-1;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
   // cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>x>>y;
        int cnt = min(x,y);
        int lo = 0, hi = 1;
        while(!abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid+1;
        }
        if(abc(lo)) cout<<lo+cnt<<endl;
        else cout<<hi+cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
