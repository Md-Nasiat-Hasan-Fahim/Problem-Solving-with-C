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

vector<pair<int, int>> mov = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> vis;
vector<string> graph;
int n, m;

bool is_valid(int x, int y)
{
    return x > -1 && x < n && y > -1 && y < m;
}

void bfs()
{
    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'L')
            {
                a = i;
                b = j;
                break;
            }
        }
        if (a != -1)
            break;
    }
    queue<pair<int, int>> q;
    vis[a][b] = true;
    q.push({a, b});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        int cnt = 0;
        for (int i = 0; i < mov.size(); i++)
        {
            if (is_valid(x + mov[i].first, y + mov[i].second) &&!vis[x + mov[i].first][y + mov[i].second]&& graph[x + mov[i].first][y + mov[i].second] == '.')
                cnt++;
        }
        if (cnt == 1||graph[x][y]=='L')
        {
            if(graph[x][y]=='.') graph[x][y]='+',vis[x][y] = true;
            for (int i = 0; i < mov.size(); i++)
            {
                if (is_valid(x + mov[i].first, y + mov[i].second) &&!vis[x + mov[i].first][y + mov[i].second]&& graph[x + mov[i].first][y + mov[i].second] == '.')
                    q.push({x + mov[i].first, y + mov[i].second});
            }
        }
        else if(cnt==0) graph[x][y]='+';
    }
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        cin >> n >> m;
        graph.clear();
        vis.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            graph.pb(s);
        }
        int x = 30;
        while(x--) bfs();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout<<graph[i][j];
            cout<<endl;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
