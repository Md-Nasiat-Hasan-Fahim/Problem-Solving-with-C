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

vector<string> graph;
vector<vector<int>> dp;
vector<int>vec;

int n, m;

bool is_valid(int x, int y)
{
    return x < 0 || y < 0;
}

bool bfs(int x, int y)
{
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = -1;
    if (is_valid(x - 1, y) || is_valid(x, y - 1))
        return dp[x][y] = 1;
    if (graph[x - 1][y] != 'X')
    {
        int tm = bfs(x - 1, y);
        if (tm != -1)
            dp[x][y] = tm;
    }
    if (graph[x][y - 1] != 'X')
    {
        int tm = bfs(x, y - 1);
        if (tm != -1)
            dp[x][y] = tm;
    }
    return dp[x][y];
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    // cin>>Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        cin >> n >> m;
        dp.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            graph.pb(s);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 'X')
                    dp[i][j] = -1;
                else if (!dp[i][j])
                    bfs(i, j);
            }
        }
        vec.assign(m+1,0);
        for(int i=0;i<m;i++)
        {
            bool ans = true;
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(graph[j][i]=='.'&&dp[j][i]==-1) ans = false;
                cnt += graph[j][i]=='.';
            }
            if(!ans) vec[i]=-1;
            else if(cnt) vec[i]=1;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            bool flag = true;
            if(a==b)
            {
                if(vec[a-1]) YES;
                else NO;
                continue;
            }
            int cnt = 0;
            for(int i=a-1;i<b;i++)
            {
                if(vec[i]==-1) flag = false;
                cnt+= (vec[i]==0);
            }
            //cout<<cnt<<endl;
            if(flag&&cnt!=m) YES;
            else NO;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}