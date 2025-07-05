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
      int a,b,c;
      cin>>a>>b>>c;
      bool ans = false;
      int x = c-b;
      int y = b - x;
      if(y%a==0&&(y/a)>0) ans = true;
      y = c - a;
      if(y%2==0)
      {
        x = a+(y/2);
        if(x%b==0&&(x/b)>0) ans = true;
      }
      x = b - a;
      y = b+x;
      if(y%c==0&&(y/c)>0) ans = true;
      if(ans) YES;
      else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
