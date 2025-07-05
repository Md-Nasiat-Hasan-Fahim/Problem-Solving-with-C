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
    //FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,t,k;
        cin>>n>>t>>k;
        int lo = 1, hi = n;
        int tem = k;
        while(hi-lo>1)
        {
            int mid = (lo+hi)/2;
            cout<<"? "<<lo<<" "<<mid<<endl;
            int x;
            cin>>x;
            int y = (mid-lo+1)-x;
            if(y>tem) hi = mid-1;
            else if(y<tem)
            {
                lo=mid+1;
                tem -=y;
            }
            else hi = mid;
        }
        int x;
        cout<<"? 1 "<<lo<<endl;
        cin>>x;
        if(lo-x==k)
        {
            cout<<"! "<<lo<<endl;
        }
        else cout<<"! "<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
