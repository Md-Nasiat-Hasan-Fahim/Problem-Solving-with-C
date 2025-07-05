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
    freopen("pails.in","r+",stdin);
    freopen("pails.out","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int mxa = c/a;
        int mxb = c/b;
        int mx = INT_MIN;
        for(int i=mxa;i>-1;i--)
        {
            int cnt = a*i+((c-a*i)/b)*b;
            mx = max(cnt,mx);
        }
        for(int i=mxb;i>-1;i--)
        {
            int cnt = b*i+((c-b*i)/a)*a;
            mx = max(cnt,mx);
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
