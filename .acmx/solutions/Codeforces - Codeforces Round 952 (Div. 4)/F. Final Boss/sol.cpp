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
      int n,h;
      cin>>h>>n;
      vector<pair<int,int>>vec(n);
      for(int i=0;i<n;i++) cin>>vec[i].first;
      for(int i=0;i<n;i++) cin>>vec[i].second;
      priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      for(int i=0;i<n;i++)
      {
        pq.push({0,i});
      }
      int turns = 0;
      while(h>0)
      {
        turns++;
        if(turns<pq.top().first)
        {
          turns = pq.top().first;
        }
        while(pq.top().first<=turns)
        {
          auto [a,i] = pq.top();
          pq.pop();
          h-=vec[i].first;
          pq.push({turns+vec[i].second,i});
          // cout<<turns+vec[i].second<<" "<<i<<endl;
        }
        cout<<h<<" "<<turns<<endl;
      }
      cout<<turns<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}