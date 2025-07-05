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
    int ara[21]={0};
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<=min(i,9LL);j++)
        {
            if(i-j>-1&&i-j<10) ara[i]++;
        }
    }
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n;
        m = n;
        vector<int>vec;
        while(m)
        {
            vec.pb(m%10);
            m/=10;
        }
        int dp[12][21][2];
        memset(dp,0,sizeof(dp));
        dp[vec.size()-1][vec[vec.size()-1]][0]=ara[vec[vec.size()-1]];
        if(vec[vec.size()-1]!=0) dp[vec.size()-1][vec[vec.size()-1]-1][0]=ara[vec[vec.size()-1]-1];
        for(int i = vec.size()-2;i>-1;i--)
        {
            dp[i][vec[i]][0]=ara[vec[i]]*(dp[i+1][vec[i+1]][0]+dp[i+1][vec[i+1]][1]);
            if(vec[i]>0)  dp[i][vec[i]-1][0]=ara[vec[i]-1]*(dp[i+1][vec[i+1]][0]+dp[i+1][vec[i+1]][1]);
            if(i+2<vec.size())
            {
                dp[i][vec[i]][1]=(ara[10+vec[i]])*((dp[i+1][vec[i+1]][0]+dp[i+1][vec[i+1]][1])/((dp[i+2][vec[i+2]][0]+dp[i+2][vec[i+2]][1])))*(dp[i+2][vec[i+2]-1][0]+dp[i+2][vec[i+2]-1][1]);
                dp[i][vec[i]-1][1]=(ara[10+vec[i]]-1)*((dp[i+1][vec[i+1]][0]+dp[i+1][vec[i+1]][1])/((dp[i+2][vec[i+2]][0]+dp[i+2][vec[i+2]][1])))*(dp[i+2][vec[i+2]-1][0]+dp[i+2][vec[i+2]-1][1]);
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
