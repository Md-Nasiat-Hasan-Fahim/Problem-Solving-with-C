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
    vector<pair<int, int>> vec;
    int n;
    cin >> n;
    vector<int> graph[n + 1];
    for (int i = 0; i < n; i++)
    {
      int u, v;
      cin >> u >> v;
      graph[u].pb(v);
      graph[v].pb(u);
      vec.pb({u, v});
    }
    for (int i = 0; i <= n; i++)
      sort(all(graph[i]));
    for (int i = 0; i < n; i++)
    {
      auto [u, v] = vec[i];
      int am=-1;
      if (u == v)
      {
        cout << u << " " << u << " " << u << endl;
        continue;
      }
      for (int j = u; j <= v; j++)
      {
        if (j == u)
        {
          if (binary_search(all(graph[j + 1]), v))
          {
            // cout<<j+1<<" "<<v<<endl;
            am = j;
            break;
          }
        }
        else if (j == v)
        {
          if (binary_search(all(graph[u]), j - 1))
          {
            // cout<<am<<" "<<v<<endl;
            am = j;
            break;
          }
        }
        else
        {
          if (binary_search(all(graph[u]), j - 1) && binary_search(all(graph[j + 1]), v))
          {
            am = j;
            break;
          }
        }
      }
      cout << u << " " << v << " " << am << endl;
    }
  }
  // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
  return 0;
}
