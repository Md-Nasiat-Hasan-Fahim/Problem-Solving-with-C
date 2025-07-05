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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
    int cnt = 0;
    unordered_map<int, vector<int>, custom_hash> mp;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      mp[a % k].pb(a);
    }
    int flag = 0;
    for (auto [i, vec] : mp)
    {
      sort(all(vec));
      flag += (vec.size() % 2);
      int m = vec.size();
      if (vec.size() % 2)
      {
        vector<int> ab(m + 2,0);
        for (int i = 1; i < m; i++)
        {
          ab[i] = vec[i] - vec[i - 1];
          if (i - 2 > -1)
            ab[i] += ab[i - 2];
        }
        int val = INT_MAX;
        for (int i = 0; i < m; i++)
        {
          int tem = 0;
          if (i % 2)
          {
            if (i - 2 > -1)
              tem += ab[i - 2];
            tem += vec[i + 1] - vec[i - 1];
            tem += ab[m - 1] - ab[i + 1];
          }
          else
          {
            if (i - 1 > -1)
              tem += ab[i - 1];
            tem += ab[m - 1] - ab[i];
          }
          val = min(val, tem);
        }
        cnt += val / k;
      }
      else
      {
        int val = 0;
        for(int i=0;i<m-1;i+=2)
        {
          val+=vec[i+1]-vec[i];
        }
        cnt+=val/k;
      }
    }
    if ((flag == 1 && n % 2 == 1) || !flag)
      cout << cnt << endl;
    else
      cout << "-1" << endl;
  }
  // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
  return 0;
}
