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

vector<vector<int>>val;
vector<int>rem;

int ans;

void dfs(int x, int len)
{
  // cout<<x<<" "<<rem[x]<<" "<<len<<endl;
  ans = max(ans,rem[x]*len);
  for(int i=0;i<2;i++)
  {
    if(val[x][i]!=-1) dfs(val[x][i], len+1);
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
      int n;
      cin>>n;
      int aloc = 0;
      val.clear();
      rem.clear();
      ans = 0;
      val.pb(vector<int>(3,-1));
      rem.pb(0);
      for(int i=0;i<n;i++)
      {
        string s;
        cin>>s;
        int root = 0;
        for(int i=0;i<s.size();i++)
        {
          if(val[root][s[i]-'0']==-1)
          {
            aloc++;
            val[root][s[i]-'0']=aloc;
            val.pb(vector<int>(3,-1));
            rem.pb(0);
          }
          // cout<<aloc<<" "<<val[root][s[i]-'0']<<" "<<rem[val[root][s[i]-'0']]<<endl;
          rem[val[root][s[i]-'0']]++;
          root = val[root][s[i]-'0'];
        }
        // cout<<endl;
      }
      dfs(0,0);
      cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
