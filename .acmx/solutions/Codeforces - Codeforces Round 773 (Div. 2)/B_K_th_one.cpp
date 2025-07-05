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
    tree.assign(4*n,0);
  }
  int update(int idx,int val, int s, int e, int node)
  {
    if(idx<s||idx>e) return tree[node];
    if(idx==s&&idx==e)
    {
      if(val!=-1) tree[node]=val;
      else tree[node] = 1-tree[node];
      return tree[node];
    }
    int mid = (s+e)/2;
    tree[node] = update(idx,val,s,mid,2*node)+update(idx,val,mid+1,e,2*node+1);
    return tree[node];
  }
  int sum(int i, int j, int s, int e, int node)
  {
    if(i>e||j<s) return 0;
    if(s>=i&&e<=j) return tree[node];
    int mid = (s+e)/2;
    int cnt = sum(i,j,s,mid,2*node) + sum(i,j,mid+1,e,2*node+1);
    return cnt;
  }

  bool abc(int lim,int n, int k)
  {
    return sum(1,lim,1,n,1)>=k;
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
      int n,m;
      cin>>n>>m;
      tr tree;
      tree.init(n+3);
      for(int i=1;i<=n;i++)
      {
        int a;
        cin>>a;
        tree.update(i,a,1,n,1);
      }
      while(m--)
      {
        int a;
        cin>>a;
        if(a==1)
        {
          int i;
          cin>>i;
          tree.update(i+1,-1,1,n,1);
        }else{
          int k;
          cin>>k;
          k++;
          int lo = 0, hi=n;
          while(hi-lo>1)
          {
            int mid = (hi+lo)/2;
            if(tree.abc(mid,n,k)) hi = mid;
            else lo = mid;
          }
          cout<<hi-1<<endl;
        }
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
