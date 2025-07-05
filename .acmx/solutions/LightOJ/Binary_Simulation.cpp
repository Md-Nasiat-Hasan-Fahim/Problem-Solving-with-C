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
  vector<int>tree;
  void init(int n)
  {
    tree.assign(4*n+4,0);
  }
  void update(int l, int r, int x, int y,int node)
  {
    if(x>r||y<l) return;
    if(l>=x&&r<=y)
    {
      tree[node]++;
      return;
    }
    int mid = (l+r)/2;
    update(l,mid,x,y,2*node);
    update(mid+1,r,x,y,2*node+1);
  }
  void query(int l, int r, int x, int node)
  {
    if(x<l||x>r) return;
    if(x==l&&x==r)
    {
      cnt+=tree[node];
      return;
    }
    cnt+=tree[node];
    int mid=(l+r)/2;
    query(l,mid,x,2*node);
    query(mid+1,r,x,2*node+1);
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
      cout<<"Case "<<tttttttt<<":\n";
      tr tre;
      string s;
      cin>>s;
      int n = s.size();
      int q;
      cin>>q;
      tre.init(n);
      for(int i=0;i<n;i++)
      {
        if(s[i]=='1')
        {
          tre.update(1,n,i+1,i+1,1);
        }
      }
      while(q--)
      {
        char c;
        cin>>c;
        if(c=='I')
        {
          int a,b;
          cin>>a>>b;
          tre.update(1,n,a,b,1);
        }
        else
        {
          int a;
          cin>>a;
          cnt = 0;
          tre.query(1,n,a,1);
          // cout<<cnt<<" ";
          cout<<cnt%2<<endl;
        }
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
