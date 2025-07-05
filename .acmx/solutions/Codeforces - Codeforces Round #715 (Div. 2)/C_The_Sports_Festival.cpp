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
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        vector<vector<int>>mx(n+1,vector<int>(n+1,INT_MIN));
        vector<vector<int>>mn(n+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<n;i++)
        {
            int am = vec[i], an = vec[i];
            for(int j=i;j<n;j++)
            {
                am = max(am,vec[j]);
                an = min(an,vec[j]);
                mx[i][j]=am;
                mn[i][j]=an;
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=j;i>-1;i--)
            {
                for(int k=i;k<=j;k++)
                {
                    int am = vec[i];
                    int an = vec[i];
                    int x = 0, y = 0;
                    if(i+1<=k)
                    {
                        am=max(am,mx[i+1][k]);
                        an=min(an,mn[i+1][k]);
                        x=dp[i+1][k];
                    }
                    if(k+1<=j)
                    {
                        am=max(am,mx[k+1][j]);
                        an=min(an,mn[k+1][j]);
                        y=dp[k+1][j];
                    }
                    dp[i][j]=min(dp[i][j],x+y+am-an);
                }
            }
        }
        cout<<dp[0][n-1]<<" "<<dp[0][1]<<" "<<dp[1][2]<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
