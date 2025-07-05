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

const int mx = 100;
vector<int> prime;
int ara[mx];

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
    cin >> Master0fTheSEA;
    sieve();
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> abc;
        for (int i = 0; i < prime.size(); i++)
        {
            int ct = 0;
            for (int j = prime[i]; j < 102; j *= prime[i])
            {
                ct += (n / j);
            }
            if (!ct)
                break;
            abc.pb({prime[i], ct});
        }
        cout << "Case " << tttttttt << ": " << n << " = ";
        for (int i = 0; i < abc.size(); i++)
            if (i != abc.size() - 1)
                cout << abc[i].first << " (" << abc[i].second << ") * ";
            else
                cout << abc[i].first << " (" << abc[i].second << ")" << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
