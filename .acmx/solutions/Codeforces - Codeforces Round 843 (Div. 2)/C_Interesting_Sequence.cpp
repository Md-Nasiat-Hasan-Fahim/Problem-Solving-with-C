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
        int n,x;
        cin>>n>>x;
        int hn = 0, hx = 0, tn = n, tx = x;
        for(int i=1;i<64&&tn;i++)
        {
            hn = i;
            tn = (tn>>1);
        }
        for(int i=1;i<64&&tx;i++)
        {
            hx = i;
            tx = (tx>>1);
        }
        if((n&x)!=x||(x!=0&&hn!=hx))
        {
            cout<<"-1\n";
            continue;
        }
        int m = x;
        for(int i=0;i<64&&m<n;i++)
        {
            int y = (1LL<<i);
            if((__int128_t)(!(y&n))) m = m + y;
        }
        for(int i=63;i>-1&&m>n;i--)
        {
            int y = (1LL<<i);
            if((__int128_t)(!(y&n))&&((y&m))&&(m-y>=n))
            m = m - y; 
        }
        tn = n;
        int td = m;
        int y = 0;
        while(td&&tn&&tn!=td)
        {
            y++;
            tn = (tn>>1);
            td = (td>>1);
        }
        if((tn<<y)==x&&m>=n)
        cout<<m<<endl;
        else cout<<"-1\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
