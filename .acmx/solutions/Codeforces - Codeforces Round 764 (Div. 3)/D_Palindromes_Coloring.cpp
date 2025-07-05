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
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int cnt[30]={0};
      for(int i=0;i<n;i++)
      {
        cnt[s[i]-'a']++;
      }
      int pr = 0, rs = 0;
      for(int i=0;i<30;i++) pr+=(cnt[i]/2),rs+=(cnt[i]%2);
      int ans = (pr/k)*2;
      if((pr%k)*2+rs>=k) ans++;
      cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
