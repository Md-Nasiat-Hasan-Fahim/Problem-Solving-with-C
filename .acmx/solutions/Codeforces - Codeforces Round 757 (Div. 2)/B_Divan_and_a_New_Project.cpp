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
        int n;
        cin >> n;
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pr.pb({a, i+1});
        }
        sort(all(pr));
        reverse(all(pr));
        int ab = 1;
        int cnt = 0;
        vector<int> vec(n + 1);
        for (int i = 0; i < n;)
        {
            vec[pr[i].second] = ab;
            cnt += pr[i].first * ab;
            i++;
            if (i < n)
            {
                vec[pr[i].second] = -ab;
                cnt += pr[i].first * ab;
                i++;
            }
            ab++;
        }
        cnt*=2;
        cout<<cnt<<endl;
        for(int i=0;i<n+1;i++) cout<<vec[i]<<" ";
        cout<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
