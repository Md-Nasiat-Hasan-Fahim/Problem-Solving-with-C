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
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec[a]=i+1;
        }
        bool ans = (vec[1]!=1);
        if(ans) vec[1]=-1;
        int cnt = 0;
        for(int i=2;i<=n&&i<100;i++)
        {
            if(vec[i]<vec[i-1])
            {
                cnt++;
                vec[i]=n+cnt;
            }
        }
        cnt = max(cnt,(int)ans);
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
