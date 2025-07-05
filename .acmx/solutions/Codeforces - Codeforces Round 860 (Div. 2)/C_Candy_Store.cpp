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

int lcm(int x, int y)
{
    int z = 1LL*x*y;
    z = z/__gcd(x,y);
    return z;
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
        int n;
        cin>>n;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            vec.pb({a,b});
        }
        int cnt = 0;
        int gc = 1, lc = 1e10;
        for(int i=0;i<n;i++)
        {
            gc = __gcd(1LL*vec[i].first*vec[i].second,gc);
            lc = lcm(vec[i].second,lc);
            if(gc%lc!=0)
            {
                cnt++;
                gc = 1LL*vec[i].first*vec[i].second;
                lc = vec[i].second;
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
