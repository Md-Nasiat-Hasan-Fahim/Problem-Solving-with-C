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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int grid[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char a;
                cin>>a;
                grid[i][j]=a-'0';
            }
        }
        int cnt = 0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                //cout<<<<endl;
                int o = 0,z = 0;
                if(grid[i][j]==1) o++;
                else z++;
                if(grid[n-1-j][i]==1) o++;
                else z++;
                if(grid[j][n-1-i]==1) o++;
                else z++;
                if(grid[n-i-1][n-1-j]==1) o++;
                else z++;
                //cout<<o<<" "<<z<<endl;
                if(o>z) cnt+=z;
                else cnt+=o;
            }
           // cout<<endl<<endl;
        }
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
