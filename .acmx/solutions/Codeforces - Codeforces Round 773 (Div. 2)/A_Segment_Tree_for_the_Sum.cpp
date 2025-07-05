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
int cnt;

struct tr{
  vector<int>tree,mn;
  void init(int n)
  {
    tree.assign(4*n,INT_MAX);
    mn.assign(4*n,0);
  }
  int update(int idx, int val, int s, int e, int node)
  {
    if(idx<s||idx>e) return tree[node];
    if(idx==s&&idx==e)
    {
      tree[node] = val;
      mn[node]=1;
      return tree[node];
    }
    int mid = (s+e)/2;
    int mn1 = update(idx,val,s,mid,2*node);
    int mn2 = update(idx,val,mid+1,e,2*node+1);
    if(mn1>mn2)
    {
      mn[node] = mn[2*node+1];
    }
    else if(mn1<mn2)
    {
      mn[node] = mn[2*node];
    }
    else mn[node] = mn[2*node]+mn[2*node+1];
    tree[node] = min(mn1,mn2);
    // cout<<node<<" "<<tree[node]<<endl;
    return tree[node];
  }

  int sum(int i, int j,int s, int e, int node)
  {
    if(i>e||j<s) return INT_MAX;
    if(s>=i&&j>=e) return tree[node];
    int mid = (s+e)/2;
    int cnt = min(sum(i,j,s,mid,2*node),sum(i,j,mid+1,e,2*node+1));
    return cnt;
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
      int n,q;
      cin>>n>>q;
      tr tree;
      tree.init(n+1);
      for(int i=1;i<=n;i++)
      {
        int a;
        cin>>a;
        tree.update(i,a,1,n,1);
      }
      while(q--)
      {
        int a;
        cin>>a;
        if(a==1)
        {
          int i,v;
          cin>>i>>v;
          tree.update(i+1,v,1,n,1);
        }
        else
        {
          int l,r;
          cin>>l>>r;
          cout<<tree.sum(l+1,r,1,n,1)<<endl;
        }
      }
      // cout<<tree.tree[1]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
