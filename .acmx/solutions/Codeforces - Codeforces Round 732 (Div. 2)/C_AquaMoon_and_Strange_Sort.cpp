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
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        vector<int> mp(100000+5,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
            vec[i]=a;
        }
        vector<int> ara(100000+5),cum(100000+5);
        int cnt = 0;
        for(int i=0;i<100000+4;i++)
        {
            cum[i]=cnt+1;
            ara[i] = (cnt+mp[i])/2 - (cnt/2);
            cnt+=mp[i];
        }
        bool ans = true;
        for(int i=0;i<n;i++)
        {
            int x = abs((i+1)-cum[vec[i]]);
            if(x%2==0)
            {
                if(cum[vec[i]]%2==0)
                {
                    if(ara[vec[i]]) {ara[vec[i]]--;mp[vec[i]]--;}
                    else ans = false;
                }
                else
                {
                    if(mp[vec[i]]-ara[vec[i]]>0) mp[vec[i]]--;
                    else ans = false;
                }
            }
            else
            {
                if(cum[vec[i]]%2==0)
                {
                    if(mp[vec[i]]-ara[vec[i]]>0) mp[vec[i]]--;
                    else ans = false;
                }
                else
                {
                    if(ara[vec[i]]) {ara[vec[i]]--;mp[vec[i]]--;}
                    else ans = false;
                }
            }
            //cout<<vec[i]<<" "<<x<<" "<<ara[vec[i]]<<" "<<ans<<endl;
            if(!ans) break;
        }
        if(ans)YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
