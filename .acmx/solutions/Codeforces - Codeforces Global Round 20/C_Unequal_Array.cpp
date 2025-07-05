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
      int n;
      cin>>n;
      vector<int>vec(n);
      for(int i=0;i<n;i++) cin>>vec[i];
      int ft = -1, bk = -1;
      for(int i=0;i<n-1;i++)
      {
        if(vec[i]==vec[i+1]) 
        {
          ft = i;
          break;
        }
      }
      for(int i = n-1;i>0;i--)
      {
        if(vec[i]==vec[i-1])
        {
          bk = i;
          break;
        }
      }
      int cnt = 0;
      if(bk-ft<3) cnt = bk-ft-1;
      else cnt = bk-ft-2;

      cout<<max(0LL,cnt)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
