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
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            vec.pb({a, i});
        }
        sort(all(vec));
        int cnt = 0;
        queue<pair<int, int>> q;
        bool ans = true;
        while (ans)
        {
            ans = false;
            for (int i = n - 1; i > -1; i--)
            {
                bool flag = true;
                while (flag && vec[i].first > 0)
                {
                    flag = false;
                    for (int j = i-1; j > -1; j--)
                    {
                        if (vec[j].first > 0)
                        {
                            cnt++;
                            q.push({vec[j].second, vec[i].second});
                            vec[j].first--;
                            vec[i].first--;
                            ans = true;
                            flag = true;
                        }
                        if (vec[i].first == 0)
                            break;
                    }
                }
            }
        }
        cout << cnt << endl;
        while (!q.empty())
        {
            cout << q.front().first + 1 << " " << q.front().second + 1 << endl;
            q.pop();
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
