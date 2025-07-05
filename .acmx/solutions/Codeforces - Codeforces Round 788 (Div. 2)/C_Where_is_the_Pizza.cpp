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

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
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
      set<int>st;
      vector<int>vec1(n),vec2(n),vec3(n);
      for(int i=0;i<n;i++) cin>>vec1[i];
      for(int i=0;i<n;i++) cin>>vec2[i];
      for(int i=0;i<n;i++) cin>>vec3[i],st.insert(vec3[i]);
      int ct = 0, cnt = 1;
      for(int i=0;i<n;i++)
      {
        if((st.count(vec1[i])||st.count(vec2[i])||(vec3[i]>0))||(vec1[i]==vec2[i]));
        else
        {
          ct++;
          cnt*=2;
          cnt%=mod;
          if(cnt<0) cnt+=mod;
          cnt%=mod;
        }
      }
      cout<<cnt<<endl;
      int mn = POW(4,mod-2);
      mn = mn*ct;
      check(mn);
      mn%=mod;
      if(mn<0) mn +=mod;
      mn%=mod;
      mn = mn*cnt;
      check(mn);
      mn%=mod;
      if(mn<0) mn +=mod;
      mn%=mod;
      cnt = cnt - mn;
      cnt%=mod;
      if(cnt<0) cnt+=mod;
      cnt%=mod;
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
