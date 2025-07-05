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
      int neg = 0, pos = 0;
      for(int i=0;i<n;i++)
      {
        if(vec[i]<0) neg++;
        else pos++;
      }
      bool flag = true;
      for(int i=0;i<n-1;i++)
      {
        int a = labs(vec[i]);
        int b = labs(vec[i+1]);
        if(i<neg) a = -1*a;
        if(i+1<neg) b = -1*b;
        if(a>b) flag = false;
      }
      if(flag) YES;
      else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
