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
const int mx = 200005;

int ara[mx];
vector<int> prime;
int dp[mx][19];

long long POW(long long n, long long r)
{
    if (r == 0)
        return 1;
    long long res = POW(n, r / 2);
    res = res * res;
    res %= mod;
    if (res < 0)
        res += mod;
    if (r % 2)
        res *= n;
    res %= mod;
    if (res < 0)
        res += mod;
    return res;
}

void sieve()
{
    prime.pb(2);
    for (int i = 3; i < mx; i += 2)
    {
        if (!ara[i])
        {
            prime.pb(i);
            for (int j = i * i; j < mx; j += i + i)
                ara[j] = 1;
        }
    }
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    // cin>>Master0fTheSEA;
    sieve();
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        if (n == 2)
        {
            cout << (vec[0] * vec[1]) / __gcd(vec[0], vec[1]) << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; prime[j] * prime[j] <= vec[i]; j++)
            {
                int ct = 0;
                while (vec[i] % prime[j] == 0)
                {
                    ct++;
                    vec[i] /= prime[j];
                }
                dp[prime[j]][ct]++;
            }
            if (vec[i] > 1)
                dp[vec[i]][1]++;
        }
        int gc = 1;
        for (int i = 2; i < mx; i++)
        {
            int ct = 0;
            for (int j = 18; j > 0; j--)
            {
                ct += dp[i][j];
                if (ct >= n - 1)
                {
                    gc = gc * POW(i, j);
                    break;
                }
            }
        }
        cout << gc << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
