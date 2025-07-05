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

int abc(int st, int ed)
{
    if(st>ed) return 1;
    int op = ed-st+2;
    return ((op*(op-1))/2)+1;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    //cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        unordered_map<int,int,custom_hash> mp1,mp2;
        int n;
        cin>>n;
        vector<int>vec1(n),vec2(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec1[i];
            mp1[vec1[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            cin>>vec2[i];
            mp2[vec2[i]]=i;
        }
        int cnt = 0;
        int lo1,hi1,lo2,hi2;
        lo1=hi1=mp1[1];
        lo2=hi2=mp2[1];
        int lo, hi;
        //for 1
        if(lo1==lo2)
        {
            cnt+=((lo1*(lo1+1))/2)+((n-lo1-1)*(n-lo1))/2;
            hi=lo=lo1;
        }
        else
        {
            if(lo2>lo1){
                cnt+=((lo1*(lo1+1))/2)+((n-lo2-1)*(n-lo2))/2;
                cnt+=((lo2-lo1)*(lo2-lo1-1))/2;
            }
            else
            {
                cnt+=((lo2*(lo2+1))/2)+((n-lo1-1)*(n-lo1))/2;
                cnt+=((lo1-lo2)*(lo1-lo2-1))/2;
            }
            lo = min(lo1,lo2);
            hi = max(hi1,hi2);
        }
        cout<<"1 "<<lo<<" "<<hi<<" "<<cnt<<endl;
        for(int i=2;i<=n;i++)
        {
            int pos1 = mp1[i];
            int pos2 = mp2[i];
            if(pos1<lo&&pos2<lo)
            {
                int mx = max(pos1,pos2);
                int mn = min(pos1,pos2);
                int x = abc(mx+1,lo-1);
                int y = abc(hi+1,n-1);
                //if(i==2) cout<<"         "<<x<<" "<<y<<" "<<lo<<" "<<hi<<endl;
                cnt+=x*y;
                lo = mn;
            }
            else if(pos1>hi&&pos2>hi)
            {
                int mn = min(pos1,pos2);
                int mx = max(pos1,pos2);
                int x = abc(0,lo-1);
                int y = abc(hi+1,mn-1);
                cnt+=x*y;
                hi = mx;
            }
            else
            {
                int mx = max(pos1,pos2);
                int mn = min(pos1,pos2);
                hi = max(hi,mx);
                lo = min(lo,mn);
            }
            cout<<i<<" "<<lo<<" "<<hi<<" "<<cnt<<endl;
        }
        cout<<cnt+1<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
