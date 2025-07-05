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
    string s, t;
    cin >> s >> t;
    queue<pair<int, char>> q;
    int j = 0;
    for (int i = 0; i < s.size() && j<t.size(); i++)
    {
      if (s[i] == t[j] || s[i] == '?')
      {
        if (s[i] == '?')
          q.push({i, t[j]});
        // cout<<s[i]<<" "<<t[j]<<endl;
        j++;
      }
    }
    // cout<<j<<endl;
    if (j != t.size())
    {
      cout << "NO" << endl;
      continue;
    }
    while (!q.empty())
    {
      auto [i, c] = q.front();
      q.pop();
      s[i] = c;
    }
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '?')
        s[i] = 'a';
    YES;
    cout << s << endl;
  }
  // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
  return 0;
}
