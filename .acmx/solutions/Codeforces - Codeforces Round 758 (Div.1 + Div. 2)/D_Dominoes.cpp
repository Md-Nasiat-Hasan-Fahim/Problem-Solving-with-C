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
const int mod = 998244353;

void add(int &a, int b, int c)
{
    int d = b+c;
    d%=mod;
    a = (a+d)%mod;
    a%=mod;
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    // cin>>Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<vector<int>> dp(n, vector<int>(4));
        vector<string> vec;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            vec.pb(s);
        }
        if (vec[n - 1][1] == 'W')
        {
            if (vec[0][0] == 'W')
                ;
            else
            {
                if (vec[0][1] == 'B')
                    dp[0][0] = 1;
                else if (vec[0][1] == 'W')
                    dp[0][1] = 1;
                else
                    dp[0][0] = dp[0][1] = 1;
            }
        }
        else if (vec[n - 1][1] == 'B')
        {
            if (vec[0][0] == 'B')
                ;
            else
            {
                if (vec[0][1] == 'B')
                    dp[0][2] = 1;
                else if (vec[0][1] == 'W')
                    dp[0][3] = 1;
                else
                    dp[0][2] = dp[0][3] = 1;
            }
        }
        else
        {
            if (vec[0][0] == 'B')
            {
                if (vec[0][1] == 'B')
                    dp[0][0] = 1;
                else if (vec[0][1] == 'W')
                    dp[0][1] = 1;
                else
                    dp[0][0] = dp[0][1] = 1;
            }
            else if (vec[0][1] == 'W')
            {
                if (vec[0][1] == 'B')
                    dp[0][2] = 1;
                else if (vec[0][1] == 'W')
                    dp[0][3] = 1;
                else
                    dp[0][2] = dp[0][3] = 1;
            }
            else
            {
                if (vec[0][1] == 'B')
                    dp[0][0] = dp[0][2] = 1;
                else if (vec[0][1] == 'W')
                    dp[0][1] = dp[0][3] = 1;
                else
                    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (vec[i - 1][1] == 'W')
            {
                if (vec[i][0] == 'W')
                    ;
                else
                {
                    if (vec[i][1] == 'B')
                        add(dp[i][0], dp[i - 1][1], dp[i - 1][3]);
                    else if (vec[i][1] == 'W')
                        add(dp[i][1], dp[i - 1][1], dp[i - 1][3]);
                    else
                        add(dp[i][0], dp[i - 1][1], dp[i - 1][3]), add(dp[i][1], dp[i - 1][1], dp[i - 1][3]);
                }
            }
            else if (vec[i - 1][1] == 'B')
            {
                if (vec[i][0] == 'B')
                    ;
                else
                {
                    if (vec[i][1] == 'B')
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][2]);
                    else if (vec[i][1] == 'W')
                        add(dp[i][3], dp[i - 1][0], dp[i - 1][2]);
                    else
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][2]), add(dp[i][3], dp[i - 1][0], dp[i - 1][2]);
                }
            }
            else
            {
                if (vec[i][0] == 'B')
                {
                    if (vec[i][1] == 'B')
                        add(dp[i][0], dp[i - 1][1], dp[i - 1][3]);
                    else if (vec[i][1] == 'W')
                        add(dp[i][1], dp[i - 1][1], dp[i - 1][3]);
                    else
                        add(dp[i][0], dp[i - 1][1], dp[i - 1][3]), add(dp[i][1], dp[i - 1][1], dp[i - 1][3]);
                }
                else if (vec[i][1] == 'W')
                {
                    if (vec[i][1] == 'B')
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][2]);
                    else if (vec[i][1] == 'W')
                        add(dp[i][3], dp[i - 1][0], dp[i - 1][2]);
                    else
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][2]), add(dp[i][3], dp[i - 1][0], dp[i - 1][2]);
                }
                else
                {
                    if (vec[i][1] == 'B')
                    {
                        add(dp[i][0], dp[i - 1][0], dp[i - 1][1]), add(dp[i][0], dp[i - 1][2], dp[i - 1][3]);
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][1]), add(dp[i][2], dp[i - 1][2], dp[i - 1][3]);
                    }

                    else if (vec[i][1] == 'W')
                    {
                        add(dp[i][1], dp[i - 1][0], dp[i - 1][1]), add(dp[i][1], dp[i - 1][2], dp[i - 1][3]);
                        add(dp[i][3], dp[i - 1][0], dp[i - 1][1]), add(dp[i][3], dp[i - 1][2], dp[i - 1][3]);
                    }
                    else
                    {
                        add(dp[i][0], dp[i - 1][0], dp[i - 1][1]), add(dp[i][0], dp[i - 1][2], dp[i - 1][3]);
                        add(dp[i][2], dp[i - 1][0], dp[i - 1][1]), add(dp[i][2], dp[i - 1][2], dp[i - 1][3]);
                        add(dp[i][1], dp[i - 1][0], dp[i - 1][1]), add(dp[i][1], dp[i - 1][2], dp[i - 1][3]);
                        add(dp[i][3], dp[i - 1][0], dp[i - 1][1]), add(dp[i][3], dp[i - 1][2], dp[i - 1][3]);
                    }
                }
            }
        }
        int cnt = 0;
        if (vec[n-1][1] == 'W')
        {
            if (vec[0][0] == 'W')
                ;
            else
            {
                if (vec[0][1] == 'B')
                    add(cnt, dp[n - 1][1], dp[n - 1][3]);
                else if (vec[0][1] == 'W')
                    add(cnt, dp[n - 1][1], dp[n - 1][3]);
                else
                    add(cnt, dp[n - 1][1], dp[n - 1][3]), add(cnt, dp[n - 1][1], dp[n - 1][3]);
            }
        }
        else if (vec[n - 1][1] == 'B')
        {
            if (vec[0][0] == 'B')
                ;
            else
            {
                if (vec[0][1] == 'B')
                    add(cnt, dp[n - 1][0], dp[n - 1][2]);
                else if (vec[0][1] == 'W')
                    add(cnt, dp[n - 1][0], dp[n - 1][2]);
                else
                    add(cnt, dp[n - 1][0], dp[n - 1][2]), add(cnt, dp[n - 1][0], dp[n - 1][2]);
            }
        }
        else
        {
            if (vec[0][0] == 'B')
            {
                if (vec[0][1] == 'B')
                    add(cnt, dp[n - 1][1], dp[n - 1][3]);
                else if (vec[0][1] == 'W')
                    add(cnt, dp[n - 1][1], dp[n - 1][3]);
                else
                    add(cnt, dp[n - 1][1], dp[n - 1][3]), add(cnt, dp[n - 1][1], dp[n - 1][3]);
            }
            else if (vec[0][1] == 'W')
            {
                if (vec[0][1] == 'B')
                    add(cnt, dp[n - 1][0], dp[n - 1][2]);
                else if (vec[0][1] == 'W')
                    add(cnt, dp[n - 1][0], dp[n - 1][2]);
                else
                    add(cnt, dp[n - 1][0], dp[n - 1][2]), add(cnt, dp[n - 1][0], dp[n - 1][2]);
            }
            else
            {
                if (vec[0][1] == 'B')
                {
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                }

                else if (vec[0][1] == 'W')
                {
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                }
                else
                {
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                    add(cnt, dp[n - 1][0], dp[n - 1][1]), add(cnt, dp[n - 1][2], dp[n - 1][3]);
                }
            }
        }
        cout<<cnt<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
