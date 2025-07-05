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
      int n;
      s = "#"+s;
      n = s.size();
      int ct = 1;
      int arr[n+2];
      for(int i=0;i<n;i++)
      {
        if(s[i]=='1')
        {
          arr[ct++] = i;
        }
      }
      int cnt = 0;
      for(int len = 1;len<ct;len++)
      {
        for(int i=1;i<ct-len;i++)
        {
          if(arr[i+len]-arr[i]==2*len)
          {
            int tem = (ct-len-i)*i;
            tem%=mod;
            if(tem<0)
            tem+=mod;
            cnt+=tem;
            cnt%=mod;
            if(cnt<0)
            cnt+=mod;
          }
        }
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
