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
int dp[2024][2024];

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    int a = 1;
    for(int i=1;i<=2023;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j]+(a*a);
            }
            else if(j==i-1)
            {
                dp[i][j]=dp[i-1][j-1]+(a*a);
            }
            else 
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+(a*a);
                if(i>=2)dp[i][j]-=dp[i-2][j-1];
            }
            a++;
        }
    }
    vector<int>vec;
    a = 1;
    int sum = 0;
    vec.pb(0);
    for(int i=1;i<=2023;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=a;
            a++;
        }
        vec.pb(sum);
    }
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        int x = (n*(n+1))/2;
        auto it = lower_bound(all(vec),x);
        int pos = it-vec.begin();
        int tot = (((pos-1)*(pos))/2)+1;
        int pop = x-*(--it);
        int npos = (2*pop)/(n+tot);
        cout<<dp[pos][npos-1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
