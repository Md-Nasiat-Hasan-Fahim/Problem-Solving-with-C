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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int mx = 1e5 + 10;

int ara[mx + 10];
vector<int> prime;

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
    sieve();
    // cin>>Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int mp[mx] = {0};
        int mark[mx];
        memset(mark, -1, sizeof(mark));
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            char c;
            int x;
            cin >> c >> x;
            int x1 = x;
            vector<int> vec;
            if (c == '-')
            {
                if (mark[x] != -1)
                {
                    for (int i = 0; prime[i]*prime[i] <= x; i++)
                    {
                        if (x % prime[i] == 0)
                        {
                            mp[prime[i]] = 0;
                        }
                    }
                    x=x1;
                    mark[x] = -1;
                    cout << "Success" << endl;
                }
                else
                {
                    cout << "Already off" << endl;
                }
            }
            else
            {
                if (mark[x] != -1)
                {
                    cout << "Already on" << endl;
                }
                else
                {
                    int flag = -1;
                    for (int i = 0; prime[i]*prime[i] <= x; i++)
                    {
                        if (x % prime[i] == 0)
                        {
                            if (mp[prime[i]] != 0)
                                flag = mp[prime[i]];
                        }
                    }
                    x=x1;
                    if (flag == -1)
                    {
                        mark[x] = 1;
                        for (int i = 0; prime[i]*prime[i] <= x; i++)
                        {
                            if (x % prime[i] == 0)
                            {
                                mp[prime[i]] = x1;
                            }
                        }
                        x = x1;
                        cout << "Success" << endl;
                    }
                    else
                        cout << "Conflict with " << flag << endl;
                }
            }
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}