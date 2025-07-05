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
      int m;
      cin>>m;
      set<char>st;
      for(int i=0;i<m;i++)
      {
        char a;
        cin>>a;
        // cout<<a<<endl;
        st.insert(a);
      }
      int mx = 0;
      int cnt = 0;
      int flag = 0;
      // cout<<n<<" "<<s<<" "<<m<<" "<<st.size()<<endl;
      for(int i=0;i<n;i++)
      {
        // cout<<cnt<<" "<<s[i]<<" "<<st.count(s[i])<<endl;
        if(st.count(s[i]))
        {
          mx = max(mx,cnt+(flag!=0));
          // cout<<cnt<<" "<<cnt+(flag!=0)<<" "<<mx<<endl;
          flag++;
          cnt = 0;
        }
        else cnt++;
      }
      cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
