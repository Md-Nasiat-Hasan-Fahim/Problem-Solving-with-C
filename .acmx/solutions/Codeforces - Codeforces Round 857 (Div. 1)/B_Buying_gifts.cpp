#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int ttt = 1;
    cin >> ttt;
    for (int z = 1; z <= ttt; z++)
    {
        int n;
        cin >> n;
        int ara[n + 1][2];
        for (int i = 0; i < n; i++)
        {
            cin >> ara[i][0] >> ara[i][1];
        }
        pair<int, int> dp[n + 1][2];
        dp[0][0] = {ara[0][0], INT_MIN};
        dp[0][1] = {INT_MIN, ara[0][1]};
        for (int i = 1; i < n; i++)
        {
            int x = labs(dp[i - 1][0].second - max(dp[i - 1][0].first, ara[i][0]));
            int y = labs(dp[i - 1][1].second - max(dp[i - 1][1].first, ara[i][0]));
            if (x < y)
                dp[i][0] = {max(dp[i - 1][0].first, ara[i][0]), dp[i - 1][0].second};
            else
                dp[i][0] = {max(dp[i - 1][1].first, ara[i][0]), dp[i - 1][1].second};
            x = labs(max(dp[i - 1][1].second, ara[i][1]) - dp[i - 1][1].first);
            y = labs(max(dp[i - 1][0].second, ara[i][1]) - dp[i - 1][0].first);
            if (x < y)
                dp[i][1] = {dp[i - 1][1].first, max(dp[i - 1][1].second, ara[i][1])};
            else
                dp[i][1] = {dp[i - 1][0].first, max(dp[i - 1][0].second, ara[i][1])};
        }
        //cout<<dp[n-1][0].first<<" "<<dp[n-1][0].second<<" "<<dp[n-1][1].first<<" "<<dp[n-1][1].second<<endl;
        int cnt = min(labs(dp[n - 1][0].first - dp[n - 1][0].second), labs(dp[n - 1][1].first - dp[n - 1][1].second));
        cout << cnt << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
