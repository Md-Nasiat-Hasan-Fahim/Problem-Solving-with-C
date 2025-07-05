#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;

string b;
int k,n;

int dp[10][1000][2][91];

int abc(int i, int md, bool issmall, int dis)
{
    if(i==n)
    return md%k == 0 && dis%k==0;
    if(dp[i][md][issmall][dis]!=-1)
    return dp[i][md][issmall][dis];
    int cnt = 0;
    int lo = 0;
    int hi = b[i]-'0';
    if(issmall) hi = 9;
    int tmd, tdis;
    for(;lo<=hi;lo++)
    {
        tmd = ((md*10)%k)+(lo%k);
        tdis = dis%k+lo%k;
        cnt+=abc(i+1,tmd,(issmall|(lo<hi)),tdis);
    }
    dp[i][md][issmall][dis] = cnt;
    return cnt;
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<z<<": ";
        int x,y;
        cin>>x>>y>>k;
        b = to_string(y);
        n=b.size();
        int cnt1 = abc(0,0,false,0);
         memset(dp,-1,sizeof(dp));
        b = to_string(x-1);
        n=b.size();
        int cnt2 = abc(0,0,false,0);
        cout<<cnt1-cnt2<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
