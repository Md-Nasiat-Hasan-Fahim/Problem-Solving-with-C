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
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
}

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

int fact[200005];
int inv[200005];

int ncr(int n, int r)
{
    if(r>n) return 0;
    int ans = fact[n]*POW(fact[r],mod-2);
    ans%=mod;
    if(ans<0)ans+=mod;
    ans*=POW(fact[n-r],mod-2);
    ans%=mod;
    if(ans<0) ans+=mod;
    return ans;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    fact[0]=1;
    for(int i=1;i<200005;i++) {fact[i]=(fact[i-1]*i)%mod;if(fact[i]<0) fact[i]+=mod;}
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        int mx = INT_MIN;
        unordered_map<int,int,custom_hash>mp;
        for(int i=0;i<n;i++) {cin>>vec[i];mp[vec[i]]++;mx=max(vec[i],mx);}
        int ans = 0;
        if(mp[mx]>1)
        {
            ans = fact[n];
        }
        else
        {
            ans = fact[mp[mx-1]]*ncr(n,2);
            ans%=mod;
            if(ans<0) ans+=mod;
            int ct = ncr(n-1,n-mp[mx-1]);
            ct%=mod;
            if(ct<0) ct+=mod;
            ans = ct*ans;
            ans%=mod;
            if(ans<0) ans+=mod;
        }
        ans%=mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
