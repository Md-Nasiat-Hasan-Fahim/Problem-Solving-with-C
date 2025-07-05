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
        unordered_map<char,int,custom_hash>mp;
        string s;
        cin>>s;
        int n = s.size();
        char dp[n];
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int j = 0;
        bool ans = false;
        char carry = 0;
        for(char i = 'a';i<='z';i++)
        {
            if(mp[i]==0) continue;
            if(!ans)
            {
                if(carry)
                {
                    while(mp[i]-1>1)
                    {
                        dp[j]=dp[n-1-j]=i;
                        mp[i]-=2;
                        j++;
                    }
                    if(mp[i]==1)
                    {
                        dp[n-1-j]=carry;
                        dp[j]=i;
                        carry = 0;
                        mp[i]--;
                        j++;
                        ans = true;
                    }
                    else
                    {
                        mp[i]=0;
                        dp[j]=dp[j+1]=i;
                        j+=2;
                    }
                }
                else
                {
                    while(mp[i]>1)
                    {
                        dp[j]=dp[n-1-j]=i;
                        mp[i]-=2;
                        j++;
                    }
                }
            }
            else
            {
                if(carry)
                {
                    while(mp[i]-1>1)
                    {
                        dp[j]=dp[n-1-j]=i;
                        mp[i]-=2;
                        j++;
                    }
                    if(mp[i]==1)
                    {
                        dp[j]=carry;
                        dp[n-1-j]=i;
                        carry = 0;
                        mp[i]--;
                        j++;
                    }
                    else
                    {
                        mp[i]=0;
                        dp[j]=dp[j+1]=i;
                        j+=2;
                    }
                }
                else
                {
                    while(mp[i]>1)
                    {
                        dp[j]=dp[n-1-j]=i;
                        mp[i]-=2;
                        j++;
                    }
                }
            }
            if(mp[i]) carry = i;
        }
        if(carry) {dp[j]=carry;}
        for(int i=0;i<n;i++) cout<<dp[i];
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
