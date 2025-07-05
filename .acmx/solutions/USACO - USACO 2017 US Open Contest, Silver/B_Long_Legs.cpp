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
int a,b;

int abc(int x)
{
    int ta = (a/x) + (a%x!=0);
    int tb = (b/x) + (b%x!=0);
    return x-1+ta+tb;
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
        cin>>a>>b;
        int ta = sqrtl(a)+1;
        int tb = sqrt(b)+1;
        int lim = sqrtl(2*max(a,b))+10;
        int ans = LONG_LONG_MAX;
        for(int i=1;i<=lim;i++)
        {
            ans = min(ans,abc(i));
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}

