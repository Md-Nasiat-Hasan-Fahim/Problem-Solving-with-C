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

struct tr{
  vector<int>tree;
  void init(int n)
  {
    tree.assign(4*n+3,0);
  }
  void update(int i, int j,int val, int s, int e, int node)
  {
    if(e<i||j<s) return;
    if(i<=s&&e<=j)
    {
      tree[node]+=val;
      return;
    }
    int mid = (s+e)/2;
    update(i,j,val,s,mid,2*node);
    update(i,j,val,mid+1,e,2*node+1);
    return;
  }
  int fd(int i, int s, int e, int node)
  {
    if(e<i||i<s) return 0;
    if(s==e) return tree[node];
    int mid = (s+e)/2;
    return fd(i,s,mid,2*node) + fd(i,mid+1,e,2*node+1) + tree[node];
  }
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    // cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      tr tree;
      int n,q;
      cin>>n>>q;
      tree.init(n+3);
      while(q--)
      {
        int a;
        cin>>a;
        if(a==1)
        {
          int l,r,v;
          cin>>l>>r>>v;
          tree.update(l+1,r,v,1,n,1);
        }else{
          int i;
          cin>>i;
          cout<<tree.fd(i+1,1,n,1)<<endl;
        }
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
