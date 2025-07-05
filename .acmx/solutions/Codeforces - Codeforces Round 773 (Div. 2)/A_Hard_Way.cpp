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
vector<pair<int,int>>vec;

int abc(int i)
{
  if(i==0)
  {
    if(vec[1].second==vec[2].second&&vec[0].second<vec[1].second) return max(vec[1].first,vec[2].first)-min(vec[1].first,vec[2].first);
    else return 0;
  }
  else if(i==1)
  {
    if(vec[0].second==vec[2].second&&vec[1].second<vec[0].second) return max(vec[0].first,vec[2].first)-min(vec[0].first,vec[2].first);
    else return 0;
  }
  else
  {
    if(vec[1].second==vec[0].second&&vec[2].second<vec[1].second) return max(vec[1].first,vec[0].first)-min(vec[1].first,vec[0].first);
    else return 0;
  }
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
      vec.assign(3,pair<int,int>());
      for(int i=0;i<3;i++) cin>>vec[i].first>>vec[i].second;
      int ans = 0;
      for(int i=0;i<3;i++) ans = max(ans,abc(i));
      cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
