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

int POW(int n, int r)
{
    if(r==0) return 1;
    int res = POW(n,r/2);
    res = res*res;
    if(r%2==1) res*=n;
    return res;
}

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    freopen("lostcow.in","r+",stdin);
    freopen("lostcow.out","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int a,b;
        cin>>a>>b;
        if(a<b)
        {
            int x = b-a;
            int y = ceil(log2(x));
            if(y%2==1) y++;
            int q = 0;
            int r = POW(2,y);
            q = 3*(POW(2,y)-1);
            cout<<1+q+b-a-r<<endl;
        }
        else if(a>b)
        {
            int x = a-b ;
            int y = ceil(log2(x));
            if(y%2==0) y++;
            int q = 0;
            int r = POW(2,y);
            q = 3*(POW(2,y)-1);
            //cout<<1+q<<endl;
            cout<<1+q-b+a-r<<endl;
        }
        else cout<<"0\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
