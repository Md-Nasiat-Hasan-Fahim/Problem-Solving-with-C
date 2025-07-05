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
      int n,r;
      cin>>n>>r;
      n=n-r;
      vector<int>vec;
      for(int i=1;i*i<=n;i++)
      {
        if(n%i==0)
        {
          if(i>r) vec.pb(i);
          if(i==(n/i)) continue;
          if((n/i)>r) vec.pb((n/i));
        }
      }
      sort(all(vec));
      cout<<"Case "<<tttttttt<<": ";
      if(vec.size())
      for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
      else cout<<"impossible";
      cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
