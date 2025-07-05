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
int n;

bool abc(int x)
{
    int tem = n;
    while(tem!=x)
    {
        tem=tem>>1;
        x=x>>1;
    }
    return tem==0;
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
        cin>>n;
        int x=1;
        int lo = 0, hi = n-1;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid - 1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
