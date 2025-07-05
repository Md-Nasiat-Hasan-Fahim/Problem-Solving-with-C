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
const int mx = 1e6 + 10;

vector<int>prime;

void sieve()
{
  vector<int> ara(mx,0);
  prime.pb(2);
  for(int i=3;i*i<mx;i+=2)
  {
    if(!ara[i])
    {
      for(int j=i*i;j<mx;j+=i+i) ara[j]=1;
    }
  }
  for(int i=3;i<mx;i+=2)
  {
    if(!ara[i]) prime.pb(i);
  }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    sieve();
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      vector<int>vec(n);
      set<int>term,div;
      for(int i=0;i<n;i++)
      {
        cin>>vec[i];
        term.insert(vec[i]);
      }
      int m = vec.size();
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<prime.size();j++)
        {
          int p = vec[i];
          while(p%prime[i]==0)
        }
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
