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
        int ara[3][2];
        cin>>ara[0][0]>>ara[0][1]>>ara[1][0]>>ara[1][1]>>ara[2][0]>>ara[2][1];
        if((ara[0][0]==ara[2][0]&&ara[0][0]==ara[1][0]&&(ara[2][1]>ara[0][1]&&ara[2][1]<ara[1][1]||ara[2][1]<ara[0][1]&&ara[2][1]>ara[1][1]))||(ara[0][1]==ara[2][1]&&ara[0][1]==ara[1][1]&&(ara[2][0]>ara[0][0]&&ara[2][0]<ara[1][0]||ara[2][0]<ara[0][0]&&ara[2][0]>ara[1][0])))
        cout<<abs(ara[0][0]-ara[1][0])+abs(ara[0][1]-ara[1][1])+2<<endl;
        else
        cout<<abs(ara[0][0]-ara[1][0])+abs(ara[0][1]-ara[1][1])<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
