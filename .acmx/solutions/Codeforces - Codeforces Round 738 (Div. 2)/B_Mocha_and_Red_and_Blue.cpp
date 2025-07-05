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
vector<vector<int>>dp;
int n;
stack<char>ans;
string s;

void build(int i, char last)
{
    if(i==-1) return;
    if(s[i]!='?')
    {
        ans.push(s[i]);
        build(i-1,s[i]);
        return;
    }
    if(last=='B')
    {
        if(dp[i][0]+1<dp[i][1])
        {
            ans.push('B');
            build(i-1,'B');
        }
        else
        {
            ans.push('R');
            build(i-1,'R');
        }
    }
    else
    {
        if(dp[i][0]<dp[i][1]+1)
        {
            ans.push('B');
            build(i-1,'B');
        }
        else
        {
            ans.push('R');
            build(i-1,'R');
        }
    }
}


signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        cin>>n;
        cin>>s;
        dp.assign(n+1,vector<int>(2));
        while(ans.size()) ans.pop();
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=INT_MAX;
            dp[i][1]=INT_MAX;
        }
        if(s[0]=='R') dp[0][1]=0;
        else if(s[0]=='B') dp[0][0]=0;
        else dp[0][0]=dp[0][1]=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='?')
            {
                dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]);
                dp[i][1]=min(dp[i-1][0],dp[i-1][1]+1);
            }
            else if(s[i]=='B')
            {
                dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]);
            }
            else dp[i][1]=min(dp[i-1][0],dp[i-1][1]+1);
        }
        if(dp[n-1][1]<dp[n-1][0])
        {
            ans.push('R');
            build(n-2,'R');
        }
        else
        {
            ans.push('B');
            build(n-2,'B');
        }
        while(!ans.empty())
        {
            cout<<ans.top();
            ans.pop();
        }
        cout<<endl;
        //cout<<min(dp[n-1][1],dp[n-1][0])<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
