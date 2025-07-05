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
      string s;
      cin>>s;
      if(n==2)
      {
        while(s.front()=='0'&&s.size()>1) s = s.substr(1,s.size()-1);
        cout<<s<<endl;
        continue;
      }
      int cnt = LONG_LONG_MAX;
      for(int i=1;i<n;i++)
      {
        vector<int>vec;
        for(int j=0;j<i-1;j++) vec.pb(s[j]-'0');
        vec.pb((s[i-1]-'0')*10+(s[i]-'0'));
        for(int j=i+1;j<n;j++) vec.pb(s[j]-'0');
        int tc = vec[0];
        if(vec[0]==1) tc = 0;
        for(int j=1;j<n-1;j++)
        {
          // cout<<vec[j]<<" ";
          if(vec[j]==1) continue;
          else if(vec[j]=='0')
          {
            cnt = 0;
            YES;
          }
          tc+=vec[j];
        }
        // cout<<tc<<endl;
        cnt = min(tc,cnt);
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
