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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    int ara[200005];
    for(int i=0;i<200005;i++)
    {
      int tem = i;
      int ct = 0;
      while(tem) tem/=3,ct++;
      ara[i] = ct;
    }
    for(int i=1;i<200005;i++) ara[i]+=ara[i-1];
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int l,r;
      cin>>l>>r;
      cout<<ara[r]-2*ara[l-1]+ara[l]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
