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
      string s;
      cin>>s;
      int n = s.size();
      int zr = -1;
      int on = -1;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='0')
        {
          zr = i;
          break;
        }
      }
      for(int i=0;i<n;i++)
      {
        if(s[i]=='1')
        {
          on = i;
          break;
        }
      }
      if(zr==-1)
      {
        cout<<"1 n n n"<<endl;
        continue;
      }
      if(on==-1)
      {
        cout<<"1 1 1 1"<<endl;
        continue;
      }
      int izr = -1;
      for(int i=on+1;i<n;i++)
      {
        if(s[i]=='0')
        {
          izr = i;
          break;
        }
      }
      if(izr==-1)
      {
        cout<<on+1<<" "<<n<<" "<<zr<<" "<<zr<<endl;
        continue;
      }
      int fg = INT_MAX;
      string sub = "1111";
      int len = n-izr;
      for(int i=0;i<n-len+1;i++)
      {
        string tem  = s.substr(i,len);
        int tfg = INT_MAX;
        for(int )
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
