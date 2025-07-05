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
      vector<int>tem;
      vector<int>pos(n);
      for(int i=0;i<n;i++)
      {
        auto it = lower_bound(all(tem),vec[i]);
        if(it==tem.end()) tem.pb(vec[i]);
        else tem[it-tem.begin()] = vec[i];
        pos[i] = tem.size();
      }
      set<int>st;
      int m = tem.size();
      for(int i=0;i<n;i++)
      {
        auto it = m - (lower_bound(all(tem),vec[i]) - tem.begin()) + 1;
        cout<<vec[i]<<" "<<it<<" "<<pos[i]<<endl;
        if(it+pos[i]==m) st.insert(i);
      }
      cout<<st.size()<<endl;
      for(auto c:st) cout<<c+1<<" ";
      cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
