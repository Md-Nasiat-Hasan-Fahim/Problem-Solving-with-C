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
    // FastIO;
    int t = 1;
    // cin>>t;
    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        set<pair<int, int>> st;
        vector<int> red, green;
        cout << "? 1" << endl;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            if (a == 0)
                continue;
            if (a % 2 == 0)
                red.pb(i);
            else
                green.pb(i);
            if (a == 1)
                st.insert({1, i});
        }
        if (red.size() > green.size())
        {
            for (int i = 0; i < green.size(); i++)
            {
                cout << "? " << green[i] << endl;
                for (int j = 1; j <= n; j++)
                {
                    int a;
                    cin >> a;
                    if (a == 1)
                        st.insert({min(green[i],j),max(green[i],j)});
                }
            }
        }
        else
        {
            for (int i = 0; i < red.size(); i++)
            {
                cout << "? " << red[i] << endl;
                for (int j = 1; j <= n; j++)
                {
                    int a;
                    cin >> a;
                    if (a == 1)
                        st.insert({min(red[i],j),max(red[i],j)});
                }
            }
        }
        cout<<"!"<<endl;
        while(!st.empty())
        {
            cout<<st.begin()->first<<" "<<st.begin()->second<<endl;
            st.erase(st.begin());
        }
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
