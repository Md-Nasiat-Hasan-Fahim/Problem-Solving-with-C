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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ft=-1, lt=-1;
        for(int i=0;i<n;i++)
        if(s[i]=='*'){ft=i;break;}
        for(int i=n-1;i>-1;i--)
        if(s[i]=='*'){lt=i;break;}
        vector<int>dp(n+1);
        int tem = ft;
        for(int i=ft+1;i<lt;i++)
        {
            if(s[i]=='.')
            {
                dp[i]=i-ft;
                //cout<<i<<" "<<lt<<endl;
                ft++;
            }
        }
        for(int i=lt-1;i>tem;i--)
        {
            if(s[i]=='.')
            {
                dp[i]=min(dp[i],lt-i);
                lt--;
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {cnt+=dp[i];}
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
