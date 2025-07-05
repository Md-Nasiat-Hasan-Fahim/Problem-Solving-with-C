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
vector<int>val;

struct tr{
  vector<int>tree;
  void init(int n)
  {
    tree.assign(n+12,0);
  }
  void insert(int node, int pos, int x, int y)
  {
    if(pos<x||pos>y) return;
    if(pos==x&&pos==y) {tree[node]=1;return;}
    int mid = (x+y)/2;
    insert(2*node,pos,x,mid);
    insert(2*node+1,pos,mid+1,y);
    tree[node] = tree[2*node] + tree[2*node+1];
  }
  void del(int node, int pos, int x, int y)
  {
    if(pos<x||pos>y) return;
    if(pos==x&&pos==y) {tree[node]=0;return;}
    int mid = (x+y)/2;
    del(2*node,pos,x,mid);
    del(2*node+1,pos,mid+1,y);
    tree[node] = tree[2*node] + tree[2*node+1];
  }
  int valu(int node, int x, int y, int l, int r)
  {
    if(y<l||x>r) return 0;
    if(x>=l&&y<=r) return tree[node];
    return valu(2*node,x,(x+y)/2,l,r)+valu(2*node+1,(x+y)/2+1,y,l,r);
  }
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      tr abc;
      int n,q;
      cin>>n>>q;
      val.assign(n+q+5,0);
      abc.init(n+q+5);
      int i;
      for(i=1;i<=n;i++) {cin>>val[i];abc.insert(1,i,1,n+q+2);}
      i--;
      // cout<<abc.valu(1,1,n+q+2,1,1)<<endl;
      while(q--)
      {
        char c;int x;
        cin>>c>>x;
        if(c=='c')
        {
          int l=1,r=n+q+1;
          if(abc.valu(1,1,n+q+2,l,r)<x)
          {
            cout<<"nano\n";
            continue;
          }
          while(r-l>1)
          {
            int mid = (r+l)/2;
          }
        }
        else
        {
          i++;
          val[i]=x;
          abc.insert(1,i,1,n+q+2);
        }
      }

    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
