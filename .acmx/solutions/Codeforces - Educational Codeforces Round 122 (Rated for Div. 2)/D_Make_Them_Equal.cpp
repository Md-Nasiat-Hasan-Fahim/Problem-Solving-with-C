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

int abc(int x)
{
  int i=0;
  while((1<<i)<=x) i++;
  i--;
  int val = (1<<i);
  if(val==x) return i;
  int rem = x - val;
  for(int j=1;j<(val/2)+2;j++)
  {
    if(val/j==rem) return i+1;
  }
  return i+2;
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
      int n,k;
      cin>>n>>k;
      vector<pair<int,int>>pr(n),sec;
      int cnt = 0;
      for(int i=0;i<n;i++) cin>>pr[i].first;
      for(int i=0;i<n;i++) cin>>pr[i].second;
      for(int i=0;i<n;i++)
      {
        int a = abc(pr[i].first);
        if(a==0) cnt+=pr[i].second;
        else sec.pb({a,pr[i].second});
      }
      sort(all(sec),[](pair<int,int> &a, pair<int,int> &b){
        long double af = a.first;
        long double as = a.second;
        long double bf = b.first;
        long double bs = b.second;
        long double ra = as/af;
        long double rb = bs/bf;
        if(ra<rb) return true;
        else if(ra>rb) return false;
        else return af>bf;
      });
      for(int i=0;i<sec.size();i++)
      {
        cout<<sec[i].first<<" "<<sec[i].second<<endl;
      }
      while(!sec.empty())
      {
        auto [a,b] = sec.back();
        sec.pop_back();
        if(a<=k)
        {
          // cout<<a<<" "<<b<<" "<<k<<endl;
          cnt+=b;
          k-=a;
        }
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
