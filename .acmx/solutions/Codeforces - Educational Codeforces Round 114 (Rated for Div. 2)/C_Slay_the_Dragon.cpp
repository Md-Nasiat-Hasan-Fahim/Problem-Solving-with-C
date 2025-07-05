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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        int sum = 0;
        for(int i=0;i<n;i++) cin>>vec[i],sum+=vec[i];
        sort(all(vec));
        int m;
        cin>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            auto it = upper_bound(all(vec),a);
            int cnt1 = LONG_LONG_MAX, cnt2 = LONG_LONG_MAX;
            if(it!=vec.begin())
            {
                int x = *prev(it,1);
                int y = sum-x;
                x = max(0LL,a-x);
                y = max(0LL,b-y);
                cnt1=x+y;
            }
            if(it!=vec.end())
            {
                int x = *it;
                int y = sum-x;
                x = max(0LL,a-x);
                y = max(0LL,b-y);
                cnt2 = x+y;
            }
            cout<<min(cnt1,cnt2)<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
