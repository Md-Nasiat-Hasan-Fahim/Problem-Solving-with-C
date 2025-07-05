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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

vector<int>dp,cnt;

void mod_add(int &a, int x, int mod)
{
    a+=x;
    a%=mod;
    if(a<0) a+=mod;
    a%=mod;
}

signed main()
{
    
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    //cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n,mod;
        cin>>n>>mod;
        dp.assign(n+2,0);
        cnt.assign(n+2,0);
        cnt[1]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            //subtraction
            mod_add(dp[i],cnt[i-1],mod);
            //floored division
            int ct = i;
            for(int j=1;j*j<=i;j++)
            {
                int x = i/(j+1);
                if(j==1)
                {
                    mod_add(dp[i],ct-x,mod);
                }
                else
                {
                    int y = (ct-x)*dp[j];
                    y%=mod;
                    mod_add(dp[i],y,mod);
                    if((i/j)>j) mod_add(dp[i],dp[(i/j)],mod);
                }
                ct = x;
            }
            //track of previous
            mod_add(cnt[i],dp[i],mod);
            mod_add(cnt[i],cnt[i-1],mod);
        }
        cout<<dp[n]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
