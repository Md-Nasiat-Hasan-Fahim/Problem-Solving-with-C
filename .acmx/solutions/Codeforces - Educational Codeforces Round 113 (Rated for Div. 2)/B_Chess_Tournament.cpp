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
        // http://xorshift.di.unimi.it/splitmix64.c
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
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;string s;
        cin>>n>>s;
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        int tot=0;
        int win = 0;
        int ctt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') {tot+=(n-1-ctt);ctt++;}
            else win++;
        }
        //cout<<win<<" "<<tot<<endl;
        tot = (n*(n-1))/2-tot;
        if(win>tot)
        {
            NO;
            continue;
        }
        char ans[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) ans[i][j]='0';
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j) ans[i][j]='X';
                    else {ans[i][j]='=';ans[j][i]='=';}
                    dp[i][j]=dp[j][i]=1;
                }
            }
            else
            {
                bool pd = false;
                //cout<<i<<" ";
                for(int j=0;j<n;j++)
                {
                    if(i==j) {ans[i][j]='X';dp[i][j]=1;dp[j][i]=1;}
                    else if(pd) continue;
                    else if(!dp[i][j]&&!dp[j][i]&&s[j]!='1')
                    {
                        pd = true;
                        ans[i][j]='+';ans[j][i]='-';
                        dp[i][j]=1;dp[j][i]=1;
                        //cout<<j<<endl;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) if(ans[i][j]=='0') ans[i][j]='=';
        }
        YES;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)cout<<ans[i][j];
            cout<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
