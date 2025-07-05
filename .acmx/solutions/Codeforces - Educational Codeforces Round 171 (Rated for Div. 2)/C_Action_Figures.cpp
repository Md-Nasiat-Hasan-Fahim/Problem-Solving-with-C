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
    // FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
      int n;
      cin>>n;
      string s;
      cin>>s;
      vector<int>flag(n+1,0);
      int cnt = 0;
      int tr = 10;
      for(int j=n-2;j>0;)
      {
        while(j>-1&&s[j]!='1'&&flag[j]!=0) j--;
        int i = j-1;
        while(i>-1&&((s[i]=='0'&&flag[i]==1)||(s[i]=='1'))&&tr--) cout<<i<<" "<<tr<<endl,i--;
        if(i>-1)
        {
          flag[i] = 1;
          flag[j] = 1;
          cnt+=(i+1);
          j--;
        }
        cout<<i<<" "<<j<<" "<<cnt<<endl;
      }
      for(int i=0, j = n-1;i<n&&j>-1 && i<=j;)
      {
        while(i<j&&j>-1&&flag[j])j--;
        while(i<j&&flag[i])i++;
        flag[i]=1;
        flag[j]=1;
        cnt+=(i+1);
        i++;
        j--;
      }
      cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
