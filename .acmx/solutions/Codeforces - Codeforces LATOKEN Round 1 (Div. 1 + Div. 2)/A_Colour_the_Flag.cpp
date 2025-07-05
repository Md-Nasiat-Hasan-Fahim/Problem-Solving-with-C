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
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int a[2]={0};
        int n,m;
        cin>>n>>m;
        vector<string>vec;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
            for(int j=0;j<m;j++)
            {
                if(vec[i][j]!='.')
                {
                    a[((vec[i][j]=='R')^((i+j)&1))] = 1;
                }
            }
        }
        if(a[0]&&a[1])NO;
        else
        {
            YES;
            int p = 0;
            if(a[1]) p = 1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    int x = i+j+p;
                    if((x&1))cout<<'R';
                    else cout<<'W';
                }
                cout<<endl;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
