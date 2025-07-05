#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        int n, m;
        cin >> n >> m;
        int x = _abs64(n - m);
        if(x==0)
        {
            cout<<"0 0\n";
            continue;
        }
        if (__gcd(n, m) >= x)
        {
            cout << __gcd(n, m) << " "
                 << "0\n";
            continue;
        }
        int m1 = LONG_LONG_MAX, m2 = LONG_LONG_MAX;
        if (n > m)
            swap(n, m);
        int x1 = ceill(1.0*n / x) * x;
        m1 = x1 - n;
        x1 = floorl(1.0*n / x) * x;
        m2 = n-x1;
        if(m2<0) m2 = LONG_LONG_MAX;
        cout<<x<<" "<<min(m1,m2)<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
