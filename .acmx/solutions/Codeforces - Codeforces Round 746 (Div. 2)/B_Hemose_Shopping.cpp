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
        // http://xorshift.di.unimi.it/splitmix64.c
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
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,p;
        cin>>n>>p;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        auto tem = vec;
        sort(all(tem));
        unordered_map<int,int,custom_hash> st, ed, vis;
        for(int i=0;i<n;i++)
        {
            if(vis[vec[i]]==1) {continue;}
            int ts = i;
            int it = lower_bound(all(tem),vec[i])-tem.begin();
            while(it<n&&vec[i]==tem[it])
            {
                it++;
            }
            int te = it-1;
            vis[vec[i]]=1;
            st[vec[i]]=ts;
            ed[vec[i]]=te;
        }
        bool ans = true;
        for(int i=0;i<n;i++)
        {
            //cout<<vec[i]<<" "<<i<<" "<<st[vec[i]]<<" "<<ed[vec[i]]<<endl;
            if((n-i-1>=p&&n-1-st[vec[i]]>=p))
            {
                if(st[vec[i]]>i) st[vec[i]]++;
                else ed[vec[i]]--;
            }
            else if((i>=p&&ed[vec[i]]>=p))
            {
                if(ed[vec[i]]<i) ed[vec[i]]--;
                else st[vec[i]]++;
            }
            else if((i>=st[vec[i]]&&i<=ed[vec[i]]));
            else ans=false;
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
