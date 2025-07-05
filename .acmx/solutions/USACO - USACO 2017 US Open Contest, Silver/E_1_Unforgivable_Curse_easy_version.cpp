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

bool comp(multiset<char> &st1, multiset<char> &st2)
{
    while(!st1.empty()&&!st2.empty())
    {
        if(*st1.begin()!=*st2.begin()) return false;
        st1.erase(st1.begin());st2.erase(st2.begin());
    }
    return st1.size()==0&&st2.size()==0;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,k;
        cin>>n>>k;
        string s,tm;
        cin>>s>>tm;
        vector<int>dp(n+2);
        multiset<char>st1,st2;
        bool ans = true;
        if(k<n)
        {
            dp[0]+=1;
            dp[k]+=1;
            dp[n-k]-=1;
        }
        for(int i=1;i<n+1;i++) dp[i]+=dp[i-1];
        for(int i=0;i<n;i++)
        {
            if(dp[i]){st1.insert(s[i]);st2.insert(tm[i]);}
            else if(s[i]!=tm[i]){ans=false;break;}
        }
        if(ans&comp(st1,st2)) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
