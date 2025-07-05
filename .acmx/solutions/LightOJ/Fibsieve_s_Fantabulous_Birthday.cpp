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
      int sum;
      cin>>sum;
      int n = ceil(sqrtl(sum));
      int ptot = ((2 + 2*(n-2)))*((n-1)/2.0);
      int rot = n%2;
      // cout<<n<<" "<<ptot<<" "<<rot<<endl;
      cout<<"Case "<<tttttttt<<": ";
      if(rot==0)
      {
        int num = ptot + n;
        // cout<<sum<<" "<<num<<" "<<n-((sum-ptot)%(n))<<endl;
        if(sum>num)
        {
          cout<<n<<" "<<n-((sum-ptot)%(n))<<endl;
        }
        else if(sum==num)
        {
          cout<<n<<" "<<n<<endl;
        }
        else
        {
          cout<<sum-ptot<<" "<<n<<endl;
        }
      }
      else
      {
        int num = ptot+n;
        if(sum>num)
        {
          cout<<n-((sum-ptot)%(n))<<" "<<n<<endl;
        }
        else if(sum==num)
        {
          cout<<n<<" "<<n<<endl;
        }
        else
        {
          cout<<n<<" "<<(sum-ptot)<<endl;
        }
      }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
