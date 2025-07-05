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
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int dp[n+1][2][6];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                for(int j=1;j<5;j++)
                {
                    if(i-j>-1)
                    {
                        if(!dp[i-j][0][0])
                        dp[i][1][j]=1;
                        else break;
                    }
                }
                for(int j=1;j<3;j++)
                {
                    if(i-j>-1)
                    {
                        if(!dp[i-j][1][0])
                        dp[i][0][j]=1;
                        else break;
                    }
                }
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                dp[i][0][0]=1;
                for(int j=1;j<3;j++)
                {
                    if(i-j>-1)
                    {
                        if(!dp[i-j][1][0])
                        dp[i][0][j]=1;
                        else break;
                    }
                }
            }
            else
            {
                dp[i][1][0]=1;
                for(int j=1;j<5;j++)
                {
                    if(i-j>-1)
                    {
                        if(!dp[i-j][0][0])
                        dp[i][1][j]=1;
                        else break;
                    }
                }
            }
        }
        bool g1 = true, g2 = true;
        for(int i=0;i<n;i++)
        {
            if(dp[i][1][4])
            {
                g1 = false;
                cout<<i<<" 1\n";
                break;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(dp[j][0][2])
            {
                g2 = false;
                cout<<j<<" 0\n";
                break;
            }
        }
        if(g1&&g2) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
