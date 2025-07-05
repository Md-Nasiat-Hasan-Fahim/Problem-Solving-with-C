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
    //cin>>t;
    unordered_map<char,bool,custom_hash>mp;
    mp['a']=true;mp['t']=true;mp['c']=true;mp['o']=true;mp['d']=true;mp['e']=true;mp['r']=true;
    for(int z=1;z<=t;z++)
    {
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.size();
        int a1=0,a2=0;
        bool ans = true;
        unordered_map<char,int,custom_hash>st1,st2;
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='@') a1++;
            else st1[s1[i]]++;
            if(s2[i]=='@') a2++;
            else {st2[s2[i]]++;}
        }
        for(char i = 'a';i<='z';i++)
        {
            int x = st1[i];
            int y = st2[i];
            if(x==y) continue;
            else if(mp[i])
            {
                if(x>y)
                {
                    if(x-y<=a2)
                    {
                        a2-=x-y;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
                else
                {
                    if(y-x<=a1)
                    {
                        a1-=y-x;
                    }
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
            else
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
