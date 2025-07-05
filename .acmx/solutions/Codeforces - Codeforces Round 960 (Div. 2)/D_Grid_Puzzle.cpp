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

int abc(vector<int> &vec)
{
  vector<int>dp(vec.size()+1,0);
  for(int i=1;i<vec.size();i++)
  {
    if(vec[i]==0) dp[i] = dp[i-1];
    else if(vec[i]<3)
    {
      if(vec[i-1]<3) dp[i] = 1+dp[i-2];
      else dp[i] = 1+dp[i-1];
    }else dp[i] = 1+dp[i-1];
    // cout<<i<<" "<<dp[i]<<endl;
  }
  return dp[vec.size()-1];
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
      vector<int>vec(n+1);
      for(int i=1;i<=n;i++) cin>>vec[i];
      vec[0]=INT_MAX;
      int mn = abc(vec);
      int cnt = 0;
      for(int i=1;i<=n;i++)
      {
        if(vec[i]>2&&vec[i-1]>2)
        {
          cnt+=1;
          vec[i] = vec[i]-2;
          vec[i-1] = vec[i-1]-2;
        }
      }
      mn = min(mn,abc(vec)+cnt);
      cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
