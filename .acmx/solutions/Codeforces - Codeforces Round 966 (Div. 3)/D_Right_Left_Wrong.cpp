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
      n++;
      vector<int>vec(n);
      for(int i=1;i<n;i++) cin>>vec[i];
      string s;
      cin>>s;
      s = "#" + s;
      for(int i=1;i<n;i++) vec[i]+=vec[i-1];
      int i=1,j=n-1;
      int cnt = 0;
      while(i<j)
      {
        while(i<j&&s[i]!='L') i++;
        while(i<j&&s[j]!='R') j--;
        if(i>=j) break;
        cnt+=vec[j]-vec[i-1];
        i++;
        j--;
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
