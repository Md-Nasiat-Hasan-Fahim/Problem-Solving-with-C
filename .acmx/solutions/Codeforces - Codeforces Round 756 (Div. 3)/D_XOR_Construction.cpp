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
    // cin>>Master0fTheSEA;
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        int n;
        cin >> n;
        vector<int> vec(n - 1);
        for (int i = 0; i < n - 1; i++)
            cin >> vec[i];
        set<int> st;
        int a = vec[0];
        st.insert(a);
        cout << a << " ";
        for (int i = 1; i < n - 1; i++)
        {
            st.insert((a ^ vec[i]));
            a = (a ^ vec[i]);
            cout << a << " ";
        }
        cout << endl;
        for (auto a : st)
        {
            // cout<<a<<" ";
            vector<int> pt;
            cout<<a<<"     ";
            pt.pb(a);
            for (int i = 0; i < n - 1; i++)
            {
                a = (a ^ vec[i]);
                // cout<<a<<" ";
                pt.pb(a);
            }
            sort(all(pt));
            for (int i = 0; i < pt.size(); i++)
                cout << pt[i] << " ";
            cout << endl;
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
