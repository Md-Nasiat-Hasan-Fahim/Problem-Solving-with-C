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
const double lim = 0.0001;

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
      vector<double>vec(n);
      for(int i=0;i<n;i++) cin>>vec[i];
      int cnt = INT_MAX;
      if(n==1)
      {
        cout<<"0"<<endl;
        continue;
      }
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
          int len = j-i;
          if(len==0) continue;
          double r = (1.0*vec[j]-vec[i])/len;
          // cout<<r<<" ";
          auto tem = vec;
          int tc = 0;
          for(int k=i-1;k>-1;k--)
          {
            if(fabsl(vec[k+1]-r-vec[k])>lim)
            {
              tc++;
              vec[k]=vec[k+1]-r;
            }
          }
          for(int k=i+1;k<n;k++)
          {
            // if(i==0&&j==2)cout<<vec[k]<<" "<<vec[k-1]<<" "<<r<<" "<<fabsl(vec[k-1]+r-vec[k])<<endl;
            // cout<<labs(vec[k-1]+r-vec[k])<<endl;
            if(fabsl(vec[k-1]+r-vec[k])>lim)
            {
              tc++;
              vec[k]=vec[k-1]+r;
            }
          }
          // cout<<i<<" "<<j<<" "<<tc<<endl;
          vec = tem;
          cnt = min(cnt,tc);
        }
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
