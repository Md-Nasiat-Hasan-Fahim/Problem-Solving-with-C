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

vector<int> vis;
vector<int> st;
int loop;
vector<vector<int>> graph;
stack<int> ans;
vector<int> cost;

void dfs(int x)
{
    vis[x] = 1;
    for (auto c : graph[x])
    {
        if (vis[c])
        {
            if (vis[c] == 1)
                loop = c;
            continue;
        }
        dfs(c);
    }
    st.pb(x);
    vis[x] = 2;
}

void abc(int x)
{
    dfs(x);
    int mark = st.size()-1;
    int tem = 0;
    reverse(all(st));
    stack<int>stt;
    if (loop)
    {
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == loop)
            {
                tem = i;
                break;
            }
            stt.push(st[i]);
        }
        int mn = INT_MAX;
        for (int i = tem; i < st.size(); i++)
        {
            if (cost[st[i]] < mn)
            {
                mn = cost[st[i]];
                mark = i;
            }
        }
        for (int i = mark+1; i < st.size(); i++)
        {
            stt.push(st[i]);
        }
    }
    for (int i = tem; i < mark+1; i++)
        stt.push(st[i]);
    while(!stt.empty())
    {
        ans.push(stt.top());
        stt.pop();
    }
    loop = 0;
    st.clear();
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
        int n;
        cin >> n;
        vis.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>());
        cost.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            graph[i + 1].pb(a);
        }
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                abc(i);
            }
        }
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
