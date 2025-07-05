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

struct make{
  int sum,pre,suf,mx;
};

struct tr{
  vector<make>tree;
  void init(int n)
  {
    tree.assign(4*n,{0,0,0,0});
  }
  make update(int idx, int val, int s, int e, int node)
  {
    if(idx<s||idx>e) return tree[node];
    if(idx==s&&idx==e)
    {
      tree[node].sum = val;
      tree[node].pre = tree[node].suf = tree[node].mx = max(0LL,val);
      return tree[node];
    }
    int mid = (s+e)/2;
    auto mk1 = update(idx,val,s,mid,2*node);
    auto mk2 = update(idx,val,mid+1,e,2*node+1);
    tree[node].sum = mk1.sum+mk2.sum;
    tree[node].mx = max({mk1.mx,mk2.mx,mk1.suf+mk2.pre,mk1.pre,mk2.suf});
    tree[node].pre = max({mk1.pre,mk1.sum+mk2.pre});
    tree[node].suf = max({mk2.suf,mk2.sum+mk1.suf});
    return tree[node];
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
      for(int i=1;i<=n;i++) 
      {
        int a;
        cin>>a;
        tree.update(i,a,1,n,1);
      }
      cout<<tree.tree[1].mx<<endl;
      while(q--)
      {
        int i,v;
        cin>>i>>v;
        tree.update(i+1,v,1,n,1);
        cout<<tree.tree[1].mx<<endl;
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
