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

string s;
int n;
vector<vector<int>> dp;

void pqr(int &cnt)
{
    cnt = cnt % mod;
    if (cnt < 0)
        cnt += mod;
}

int abc(int pos, int stat)
{
    if (dp[pos][stat] != -1)
        return dp[pos][stat];
    if (n % 2 == 0 && pos == (n / 2) - 1)
    {
        if (stat)
            return 26;
        int x = s[pos] - 'A';
        for (int i = pos; i > -1; i--)
            if (s[i] > s[n - i - 1])
            {
                x--;
                break;
            }
            else if (s[n - i - 1] > s[i])
                break;
        return x + 1;
    }
    if (pos == n / 2)
    {
        int x = 1;
        if (n % 2)
        {
            if (stat)
                return 26;

            int x = s[pos] - 'A';
            for (int i = pos; i > -1; i--)
                if (s[i] > s[n - i - 1])
                {
                    x--;
                    break;
                }
                else if (s[n - i - 1] > s[i])
                    break;
            return x + 1;
        }
        return x;
    }
    int cnt = 0;
    int x = s[pos] - 'A';
    if (stat)
    {
        cnt += (26 * abc(pos + 1, stat) % mod);
        pqr(cnt);
    }
    else
    {
        cnt += abc(pos + 1, 0);
        pqr(cnt);
        cnt += (x * abc(pos + 1, 1) % mod);
        pqr(cnt);
    }
    return dp[pos][stat] = cnt;
}

signed main()
{
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        cin >> n >> s;
        dp.assign(n + 1, vector<int>(2, -1));
        cout << abc(0, 0) << endl;
    }
    return 0;
}
