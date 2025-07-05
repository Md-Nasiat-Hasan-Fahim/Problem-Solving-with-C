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
vector<int>vec;
int n,w,k;

int indx(int m)
{
  return lower_bound(all(vec),m-w)-vec.begin()-1;
}

int count(int m)
{
  return upper_bound(all(vec),m) - lower_bound(all(vec),m-w);
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
      vec.clear();
      cin>>n>>w>>k;
      for(int i=0;i<n;i++)
      {
        int a,b;
        cin>>a>>b;
        vec.pb(b);
      }
      sort(all(vec));
      int dp[n+1][k+1];
      memset(dp,0,sizeof(dp));
      for(int i=0;i<n;i++)
      {
        for(int j=1;j<=k;j++)
        {
          int ct = count(vec[i]);
          int idx = indx(vec[i]);
          if(idx>-1) ct+=dp[idx][j-1];
          dp[i][j]=max(ct,dp[i][j-1]);
          if(i-1>-1) dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
      }
      cout<<"Case "<<tttttttt<<": ";
      cout<<dp[n-1][k]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
