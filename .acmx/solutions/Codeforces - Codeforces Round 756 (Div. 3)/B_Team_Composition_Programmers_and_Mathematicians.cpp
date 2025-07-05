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

int abc(int a, int b)
{
    if(a==0||b==0) return 0;
    if(a+b<4) return 0;
    if(a+b==4) return 1;
    int cnt = 0;
    //cout<<a<<" "<<b<<endl;
    for (int i = 3; i > 0; i--)
    {
        int ct = a / i;
        int j = 4 - i;
        int bt = min(b / j, ct);
        int tm = min(ct, bt);
        int x = a - tm*i; int y = b - tm*j;
        if(x!=a&&y!=b)cnt = max(cnt, tm+abc(x,y));
        else cnt = max(cnt, tm);
    }
    return cnt;
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int cnt = 0;
        int a, b;
        cin >> a >> b;
        cout << abc(a,b) << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
