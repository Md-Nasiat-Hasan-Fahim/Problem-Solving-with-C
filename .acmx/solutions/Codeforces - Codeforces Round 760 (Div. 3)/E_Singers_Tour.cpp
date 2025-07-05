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

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i], sum += vec[i];
        int itx = (n * (n + 1)) / 2;
        bool ans = true;
        if (sum % itx)
        {
            ans = false;
        }
        sum /= itx;
        int a = sum - (vec[0] - vec[n - 1]);
        vector<int> pq;
        if (a < 1 || a % n)
        {
            ans = false;
        }
        pq.pb(a / n);
        for (int i = 1; i < n; i++)
        {
            a = sum - (vec[i] - vec[i - 1]);
            if (a < 1 || a % n)
            {
                ans = false;
            }
            pq.pb(a / n);
        }
        if(ans)
        {
            YES;
            for(int i=0;i<n;i++) cout<<pq[i]<<" ";
            cout<<endl;
        }
        else NO;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
