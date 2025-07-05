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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        string s;
        cin>>s;
        int dp[s.size()+1][s.size()+1];
        for(int j=0;j<s.size();j++)
        {
            for(int i=j;i>-1;i--)
            {
                if(i==j) dp[i][j]=0;
                else
                {
                    if(s[i]==s[j])
                    {
                        if(i+1<=j-1) dp[i][j] = min(dp[i+1][j-1],1+dp[i+1][j]);
                        else dp[i][j]=min(0LL,1+dp[i+1][j]);
                    }
                    else
                    {
                        dp[i][j]=min(1+dp[i+1][j],1+dp[i][j-1]);
                    }
                }
            }
        }
        cout<<"Case "<<z<<": ";
        cout<<dp[0][s.size()-1]<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
