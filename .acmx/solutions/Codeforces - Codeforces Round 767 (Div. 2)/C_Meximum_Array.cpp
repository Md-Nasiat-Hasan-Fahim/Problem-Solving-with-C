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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
      unordered_map<int,int,custom_hash>st,tem;
      for(int i=0;i<n;i++) cin>>vec[i],st[vec[i]]++;
      vector<int>ans;
      stack<int>stk;
      int val = 0;
      for(int i=0;i<n;i++)
      {
        tem[vec[i]]++;
        stk.push(vec[i]);
        while(tem[val]) val++;
        if(!st[val])
        {
          // cout<<i<<" "<<val<<" "<<st.size()<<" "<<stk.size()<<endl;
          ans.pb(val);
          tem.clear();
          val = 0;
          while(!stk.empty())
          {
            st[stk.top()]--;
            // cout<<st.size()<<endl;
            stk.pop();
          }
          // cout<<i<<" "<<st.size()<<endl; 
        }
      }
      cout<<ans.size()<<endl;
      for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
      cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
