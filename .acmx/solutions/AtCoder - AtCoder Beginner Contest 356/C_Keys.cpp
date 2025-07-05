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

vector<vector<int>> vec;
int n, m, k;

bool is_correct(int x)
{
  for (int i = 0; i < m; i++)
  {
    int ct = 0;
    for (int j = 0; j < vec[i].size() - 1; j++)
      if (((1 << vec[i][j]) & x))
        ct++;
    // cout<<i<<" "<<vec[i][vec[i].size()-1]<<" "<<ct<<endl;
    if((vec[i][vec[i].size()-1]=='o'&&ct<k)||(vec[i][vec[i].size()-1]=='x'&&ct>=k)) return false;
  }
  return true;
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
    cin >> n >> m >> k;
    vec.assign(m, vector<int>());
    for (int i = 0; i < m; i++)
    {
      int a;
      cin >> a;
      for (int j = 0; j < a; j++)
      {
        int b;
        cin >> b;
        vec[i].pb(b);
      }
      char b;
      cin >> b;
      vec[i].pb(b);
    }
    int cnt = 0;
    int ct = (1<<n);
    for(int i=0;i<=ct;i++)
    {
      if(is_correct(i)) cnt++;
    }
    cout<<cnt<<endl;
  }
  // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
  return 0;
}
