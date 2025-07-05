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

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        int ans = 0;
        int dp[n + 1][2];
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i < n; i++)
        {
            if (vec[i] == vec[i - 1])
            {
                ans++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (vec[i] > vec[i - 1])
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
            }
            else if (vec[i] == vec[i - 1])
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
            }
            else
            {
                dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
            }
        }
        //cout<<dp[2][0]<<" "<<dp[2][1]<<endl;
        cout << ans + min(dp[n - 1][0], dp[n - 1][1] + 1) << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
