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

int dx, dy;
int n,m;
int desx,desy;

int abc(int x, int y)
{
  // cout<<x<<" "<<y<<endl;
  if(y==desy||x==desx) return 0;
  if(x+dx>n) dx=-dx;
  if(y+dy>m) dy=-dy;
  return abc(x+dx,y+dy)+1;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    // FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      dx = 1,dy = 1;
      int stx,sty;
      cin>>n>>m>>stx>>sty>>desx>>desy;
      // YES;
      cout<<abc(stx,sty)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
