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
      set<int>st;
      vector<int>vec;
      for(int i=0;i<n;i++)
      {
        int a;
        cin>>a;
        if(a<=n&&!st.count(a)) st.insert(a);
        else vec.pb(a);
      }
      for(int i=0;i<vec.size();i++)
      {
        while(1)
        {
          if(vec[i]==0||(!st.count(vec[i])&&vec[i]<=n))
          {
            st.insert(vec[i]);
            break;
          }
          vec[i]/=2;
        }
      }
      int i=1;
      for(;i<=n;i++)
      {
        // cout<<i<<" "<<*st.begin()<<endl;
        if(st.empty()||*st.begin()!=i) break;
        st.erase(st.begin());
      }
      if(i==n+1) cout<<"YES\n";
      else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
