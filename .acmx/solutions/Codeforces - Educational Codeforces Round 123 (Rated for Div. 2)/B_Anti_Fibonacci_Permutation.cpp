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
    vector<vector<int>>v0,v1,v2;
    vector<int>tem0={2,3,4},tem1 = {3,4,5,6},tem2 = {7,8,9,10};
    do{
      v1.pb(tem1);
    }while(next_permutation(tem1.begin(),tem1.end()));

    do{
      v2.pb(tem2);
    }while(next_permutation(tem2.begin(),tem2.end()));

    do{
      v0.pb(tem0);
    }while(next_permutation(tem0.begin(),tem0.end()));

    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      if(n==3)
      {
        cout<<"2 3 1\n"<<"3 1 2\n"<<"3 2 1\n";
        continue;
      }
      else if(n<6)
      {
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<v0[0].size();j++) cout<<v0[i][j]<<" ";
          cout<<endl;
        }
      }
      else if(n<11)
      {
        
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
