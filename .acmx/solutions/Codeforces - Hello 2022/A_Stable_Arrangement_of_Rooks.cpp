#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n,k;
      cin>>n>>k;
      if(k>ceil(n/2.0))
      {
        cout<<"-1\n";
        continue;
      }
      char vec[n][n];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(i==j&&i%2==0&&k) cout<<'R',k--;
          else cout<<'.';
        }
        cout<<endl;
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
