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
        int q;
        cin>>q;
        int lo = 1, hi = 1e18;
        while(q--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int a,b,n;
                cin>>a>>b>>n;
                int up = (n-1)*(a-b) + a;
                int dn = (n-2)*(a-b) + a + 1;
                //cout<<up<<" "<<dn<<" ";
                if(n==1) dn = 1;
                if(up<lo||dn>hi) cout<<"0 ";
                else
                {
                    cout<<"1 ";
                    lo = max(lo,dn);
                    hi = min(hi,up);
                }
                //cout<<hi<<" "<<lo<<endl;
            }
            else
            {
                int a,b;
                cin>>a>>b;
                /*if(hi==LONG_LONG_MAX)
                {
                    cout<<"-1 ";
                    continue;
                }*/
                int hx = hi - a;
                hx = ceil(1.0*hx/(a-b));
                hx = max(hx,0LL)+1;
                int lx = lo - a;
                lx = ceil(1.0*lx/(a-b));
                lx = max(lx,0LL)+1;
                if(lx==hx) cout<<lx<<" ";
                else cout<<"-1 ";
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
