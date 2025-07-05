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
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        vector<pair<int,int>>vec[100005];
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a;
                cin>>a;
                vec[a].pb({i,j});
            }
        }
        int cnt = 0;
        for(int i=1;i<=100000;i++)
        {
            int xn = vec[i].size();
            for(int j=1;j<vec[i].size();j++)
            {
                cnt+=(xn-j)*(abs(vec[i][j-1].first-vec[i][j].first)+abs(vec[i][j-1].second-vec[i][j].second));
            }
            if(i==1||i==2)
            cout<<i<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
