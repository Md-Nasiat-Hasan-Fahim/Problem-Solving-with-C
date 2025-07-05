#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
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
        set<int> st;
        unordered_map<int, int, custom_hash> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            st.insert(vec[i]);
            mp[vec[i]]++;
        }
        bool ans = false;
        while (!st.empty())
        {
            int x = *st.begin();
            st.erase(st.begin());
            if (mp[x] >= (n / 2))
            {
                ans = true;
                break;
            }
        }
        if (ans)
        {
            cout << "-1" << endl;
            continue;
        }
        int pt = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int y1 = abs(vec[i] - vec[j]);
                queue<int> q;
                for (int y = 1; y * y <= y1; y++)
                {
                    if(y1%y) continue;
                    q.push(y1 / y);
                    int cnt = 1;
                    for (int k = 0; k < n; k++)
                    {
                        if (i == k)
                            continue;
                        if ((vec[i] - vec[k]) % y == 0)
                            cnt++;
                    }
                    if (cnt >= n / 2)
                    {
                        pt = max(pt, y);
                    }
                }
                while (!q.empty())
                {
                    int y = q.front();
                    q.pop();
                    int cnt = 1;
                    for (int k = 0; k < n; k++)
                    {
                        if (i == k)
                            continue;
                        if ((vec[i] - vec[k]) % y == 0)
                            cnt++;
                    }
                    if (cnt >= n / 2)
                    {
                        pt = max(pt, y);
                    }
                }
            }
        }
        cout << pt << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
