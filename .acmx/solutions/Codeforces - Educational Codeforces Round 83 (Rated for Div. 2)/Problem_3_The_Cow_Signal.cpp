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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    freopen("cowsignal.in","r+",stdin);
    freopen("cowsignal.out","w+",stdout);
    FastIO;
    int t=1;
   // cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        char vec[n*k][m*k];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char a;
                cin>>a;
                int x = i*k;
                int y = j*k;
                for(int l=0;l<k;l++)
                {
                    for(int p=0;p<k;p++)
                    {
                        vec[x+l][y+p]=a;
                    }
                }
            }
        }
        for(int i=0;i<n*k;i++){
        for(int j=0;j<m*k;j++)
        cout<<vec[i][j];
        cout<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
