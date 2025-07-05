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
const int mod = 998244353;

long long POW(long long n, long long r)
{
    if(r==0) return 1LL;
    long long res = POW(n,r/2);
    res = 1LL*res*res;
    res%=mod;
    if(r%2LL==1LL) res = 1LL*n*res;
    res%=mod;
    return res;
}

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
    vector<int>fact(2*100002);
    fact[0]=1;
    for(int i=1;i<200002;i++)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        int mx = INT_MIN;
        unordered_map<int,int,custom_hash>mp;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            mp[a]++;
            mx = max(mx,a);
        }
        //cout<<mx<<" "<<mp[mx-1]<<" "<<fact[n]<<endl;
        if(mp[mx]>1) cout<<fact[n]%mod<<endl;
        else
        {
            int m = mp[mx-1];
            int ans = fact[n]*POW(m+1,mod-2);
            ans%=mod;
            ans = fact[n]-ans;
            ans%=mod;
            if(ans<0) ans+=mod;
            cout<<ans<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
