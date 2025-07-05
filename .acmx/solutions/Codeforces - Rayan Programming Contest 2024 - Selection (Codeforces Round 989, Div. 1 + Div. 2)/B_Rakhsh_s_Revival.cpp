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
      int n,m,k;
      cin>>n>>m>>k;
      string s;
      cin>>s;
      string s2 = s;
      int ct1 = 0, ct2;
      int tm = 0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='0') tm++;
        else tm = 0;
        if(tm==m)
        {
          for(int j=i;j<min(i+k,n);j++) s[j] = '1';
          tm = 0;
          ct1++;
        }
      }
      tm = 0;
      for(int i=n-1;i>-1;i--)
      {
        if(s2[i]=='0') tm++;
        else tm = 0;
        if(tm==m)
        {
          for(int j=i;j>max(i-k,-1LL);j--) s2[j] = '1';
          tm = 0;
          ct2++;
        }
      }
      cout<<min(ct1,ct2)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
