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
vector<int>vec;

bool abc(int x)
{
    int cnt = 1;
    for(int i=0;i<n;)
    {
        int y = vec[i]+x;
        if(lower_bound(all(vec),y)==vec.end()) break;
        i = lower_bound(all(vec),y) - vec.begin();
        cnt++;
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
        int lo = 1, hi = 1;
        while(abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (lo+hi)/2;
            if(abc(mid)) lo = mid;
            else hi = mid-1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
