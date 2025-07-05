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
    int n, k;
    cin >> n >> k;
    int odd = ceil((n*k) / 2.0);
    int even = (n*k) / 2;
    int odd_rows = ceil(n / 2.0);
    if (odd_rows * k != odd)
    {
      NO;
      continue;
    }
    YES;
    vector<vector<int>> vec(n, vector<int>(k));
    int o = 1, e = 2;
    for (int i = 0; i < n; i++)
    {
      if (i % 2)
      {
        for (int p = 0; p < k; p++)
        {
          vec[i][p] = e;
          e+=2;
        }
      }
      else
      {
        for (int p = 0; p < k; p++)
        {
          vec[i][p] = o;
          o+=2;
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < k; j++)
        cout << vec[i][j] << " ";
      cout << endl;
    }
  }
  // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
  return 0;
}
