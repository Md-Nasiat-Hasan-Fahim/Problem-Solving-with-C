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
        int n, m;
        cin >> n >> m;
        vector<set<int>> graph(n + 1);
        int ara[n + 1] = {0};
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            if (u > v)
            {
                if (ara[v] == 0)
                    cnt++;
                ara[v]++;
            }
            else
            {
                if (ara[u] == 0)
                    cnt++;
                ara[u]++;
            }
            graph[u].insert(v);
            graph[v].insert(u);
        }
        int q;
        cin >> q;
        while (q--)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                int u, v;
                cin >> u >> v;
                if (u > v)
                {
                    if (ara[v] == 0)
                        cnt++;
                    ara[v]++;
                }
                else
                {
                    if (ara[u] == 0)
                        cnt++;
                    ara[u]++;
                }
                graph[u].insert(v);
                graph[v].insert(u);
            }
            else
            {
                
            }
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
