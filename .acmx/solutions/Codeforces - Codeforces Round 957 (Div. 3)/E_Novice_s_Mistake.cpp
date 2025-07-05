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

int got(int n, int i)
{
  int m = n;
  int cnt = 10;
  while(m>9)
  {
    cnt = cnt*10;
    m/=10;
  }
  int j = 0;
  int val = 0;
  while(j<i)
  {
    val = val*cnt+n;
    j++;
  }
  return val;
}



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
      // cout<<got(10,5)<<endl;
      int m = to_string(n).size();
      int cnt = 0;
      vector<pair<int,int>> ans;
      int mx = 0;
      for(int i=1;;i++)
      {
        mx = max(mx,got(n,i));
        if(mx>1000000000LL) break;
      }
      string s = to_string(mx);
      // cout<<s<<endl;
      for(int i=0;i<s.size();i++)
      {
        int val = 0;
        // cout<<i<<":"<<endl;
        for(int j=0;j<=i;j++)
        {
          val = val*10 + (s[j]-'0');
          // cout<<val<<" ";
        }
        // cout<<endl;
        int m1 = to_string(val).size();
        for(int a=1;a<=10000;a++)
        {
          int b = a*n - val;
          if(b<1) continue;
          if(a*m-b==m1)
          {
            cnt++;
            ans.push_back({a,b});
          }
        }
      }

      cout<<cnt<<endl;
      for(int i=0;i<cnt;i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
