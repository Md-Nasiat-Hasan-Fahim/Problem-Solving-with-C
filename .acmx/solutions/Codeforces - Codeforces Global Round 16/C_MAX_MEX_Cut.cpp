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
        string s1, s2;
        cin >> n >> s1 >> s2;
        int cnt = 0;
        vector<pair<int, char>> vec;
        for (int i = 0; i < n; i++)
        {
            if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1'))
                cnt += 2;
            else
            {
                vec.pb({i, s1[i]});
            }
        }
        int prev = 1;
        for (int i = 1; i < vec.size(); i++)
        {
            int px = vec[i - 1].first;
            char pc = vec[i - 1].second;
            int cx = vec[i].first;
            char cc = vec[i].second;
            if (cx - px == 1)
            {
                if (cc != pc)
                {
                    if (prev != -1)
                    {
                        prev = -1;
                        cnt += 2;
                    }
                    else
                    {
                        prev = 1;
                    }
                }
                else
                {
                    if (prev != -1)
                    {
                        if (pc == '0')
                            cnt++;
                    }
                    else
                    {
                        prev = 1;
                    }
                }
            }
            else
            {
                if (prev != -1)
                {
                    cnt += (pc == '0');
                }
                else
                {
                    prev = 1;
                }
            }
        }
        if (prev != -1 && vec.size())
            cnt += (vec[vec.size() - 1].second == '0');
        cout << cnt << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
