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

void dfs(int node, string &cur, string &ans, vector<vector<int>> &tree, vector<bool> &isend)
{
    if (isend[node] && cur.length() > ans.length())
        ans = cur;
    for (int i = 0; i < 26; i++)
    {
        if (tree[node][i] && isend[tree[node][i]])
        {
            cur.push_back('a' + i);
            dfs(tree[node][i], cur, ans, tree, isend);
            cur.pop_back();
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
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        vector<string> vec;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            vec.pb(s);
        }
        vector<vector<int>> tree;
        vector<bool> isend;
        tree.push_back(vector<int>(26));
        isend.push_back(false);
        int node = 0;
        n = 0;
        for (auto s : vec)
        {
            node = 0;
            for (char c : s)
            {
                if (tree[node][c - 'a'] == 0)
                {
                    n++;
                    tree[node][c - 'a'] = n;
                    tree.push_back(vector<int>(26));
                    isend.push_back(false);
                }
                node = tree[node][c - 'a'];
            }
            isend[node] = true;
        }
        string ans = "";
        string cur = "";
        dfs(0, cur, ans, tree, isend);
        cout << ans << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
