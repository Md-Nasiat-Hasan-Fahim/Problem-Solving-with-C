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
      int sum = 0;
      int cnt = 0;
      for(int i=0;i<s.size()-1;i++)
      {
        int a = s[i]-'0';
        int b = s[i+1] - '0';
        if(a+b>9) cnt++;
        sum = max(sum,a+b);
      }
      if(sum>9)
      {
        int indx = -1;
        for(int i=s.size()-1;i>0;i--)
        {
          if(s[i]-'0'+s[i-1]-'0'==sum)
          {
            indx = i-1;
            break;
          }
        }
        for(int i=0;i<indx;i++) cout<<s[i];
        cout<<sum;
        for(int i=indx+2;i<s.size();i++) cout<<s[i];
        cout<<endl;
      }
      else
      {
        cout<<s[0]-'0'+s[1]-'0';
        for(int i=2;i<s.size();i++) cout<<s[i];
        cout<<endl;
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
