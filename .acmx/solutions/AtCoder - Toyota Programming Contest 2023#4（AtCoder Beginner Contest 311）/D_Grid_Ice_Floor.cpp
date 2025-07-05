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
int vis[200][200];
vector<string> graph;
int n, m;
vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool is_valid(int i, int j)
{
    return i > -1 && i < n && j > -1 && j < m;
}

int dfs(int i, int j)
{
    vis[i][j] = true;
    int cnt = 1;
    for (int k = 0; k < 4; k++)
    {
        int ti = mv[k].first + i;
        int tj = mv[k].second + j;
        if (is_valid(ti, tj) and !vis[ti][tj] and graph[ti][tj] != '#')
            cnt += dfs(ti, tj);
    }
    return cnt;
}

signed
main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    // cin>>Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            graph.pb(s);
        }
        cout << dfs(1, 1) << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
