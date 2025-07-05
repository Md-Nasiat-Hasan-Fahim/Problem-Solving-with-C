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
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      vector<int>vec(n);
      queue<int>ev,od;
      for(int i=0;i<n;i++)
      {
        cin>>vec[i];
        if(i!=0&&i!=n-1)
        {
          if(vec[i]%2) od.push(vec[i]);
          else ev.push(vec[i]);
        }
      }
      int cnt = 0;
      while(od.size()>1)
      {
        int a = od.front();od.pop();
        int b = od.front();od.pop();
        a--;
        b++;
        if(a) ev.push(a);
        ev.push(b);
        cnt++;
      }
      while(!od.empty()&&!ev.empty())
      {
        int a = od.front();
        od.pop();
        int b = -1;
        if(!od.empty())
        {
          b = od.front();
          od.pop();
        }
        a++;
        b++;
        int c = ev.front();ev.pop();
        c-=2;
        ev.push(a);
        if(b) ev.push(b);
        if(c) ev.push(c);
        cnt++;
      }
      // cout<<ev.size()<<endl;
      if(!od.empty())
      {
        cout<<"-1"<<endl;
        continue;
      }
      while(!ev.empty())
      {
        int a = ev.front();
        cnt+=a/2;
        ev.pop();
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
