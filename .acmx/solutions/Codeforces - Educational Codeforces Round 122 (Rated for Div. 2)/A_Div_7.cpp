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

int abc(int x, int tem)
{
  string sx = to_string(x);
  string st = to_string(tem);
  if(st.size()!=sx.size()) return INT_MAX;
  int cnt = 0;
  for(int i=0;i<st.size();i++)
  {
    cnt+=(st[i]!=sx[i]);
  }
  return cnt;
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
      int cnt = INT_MAX;
      int num = -1;
      for(int i=-1030;i<1030;i++)
      {
        int tem = n+i;
        if(tem<0||tem%7!=0) continue;
        if(abc(n,tem)<cnt)
        {
          cnt = abc(n,tem);
          num = tem;
        }
      }
      cout<<num<<endl;
      
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
