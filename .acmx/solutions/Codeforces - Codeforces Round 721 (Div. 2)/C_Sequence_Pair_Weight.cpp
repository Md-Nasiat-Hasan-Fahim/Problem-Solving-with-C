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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
        unordered_map<int,int,custom_hash>mp,mx,last,dp,first;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
            mx[a]=mp[a];
            vec.pb(a);
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(mx[vec[i]]!=mp[vec[i]])
            {
                int l = last[vec[i]];
                int x = mx[vec[i]]-mp[vec[i]];
                dp[i]=max(0LL,dp[l]-((i-l)*(1+first[vec[i]])*(x-1))+x-1) + (first[vec[i]]+1)*(n-i)*x;
                //cout<<i<<" "<<l<<" "<<x<<" "<<dp[i]<<" "<<first[vec[i]]<<endl;
            }
            else first[vec[i]]=i;
            mp[vec[i]]--;
            last[vec[i]]=i;
            cnt+=dp[i];
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
