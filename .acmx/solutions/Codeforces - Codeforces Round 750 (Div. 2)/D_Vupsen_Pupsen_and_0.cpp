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
const int mod = 1e9;

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        bool flag = true;
        int j = 0;
        int tb = accumulate(all(vec), 0LL);
        while (flag && j < n)
        {
            int a = vec[j];
            int b = tb - a;
            int c = __gcd(abs(b),a);
            int pqr = abs(-b/c) + (n-1)*abs(a/c);
            if (b != 0 && (abs(b/c)<=mod&&a/c<=mod&&pqr<=mod))
            {
                for(int i=0;i<n;i++)
                {
                    if(i==j) cout<<(-b)/c<<" ";
                    else cout<<a/c<<" ";
                }
                cout<<endl;
                flag = false;
            }
            j++;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
