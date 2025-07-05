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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

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
        string s;
        cin>>s;
        int dp[n+1];
        for(int i=0;i<n;i++) dp[i] = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') dp[i]=1;
        }
        int cnt = -1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]) cnt=0;
            else
            {
                if(cnt!=-1)
                {
                    dp[i]=min(dp[i],cnt);
                    cnt++;
                }
            }
        }
        cnt = -1;
        for(int i=n-1;i>-1;i--)
        {
            if(dp[i]) cnt = 1;
            else
            {
                if(cnt!=-1)
                {
                    dp[i]=min(dp[i],cnt);
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]<=k)
            cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
