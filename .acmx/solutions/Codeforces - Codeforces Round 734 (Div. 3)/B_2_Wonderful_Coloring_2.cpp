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
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        vector<int> flag(n + 1);
        vector<int> clr[n + 1];
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            flag[vec[i]]++;
            clr[vec[i]].pb(i);
        }
        int left = n;
        int clrm = 0;
        for (int i = 0; i < n; i++)
        {
            if (clr[vec[i]].size() < k)
            {
                if (left >= (k - clrm))
                {
                    left--;
                    ans[i]=clrm+1;
                    clrm++;
                    clrm %= k;
                }
                else
                {
                    ans[i]=0;
                    left--;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if(clr[i].size()>=k)
            {
                for(int j=0;j<k;j++)
                {
                    ans[clr[i][j]]=clrm+1;
                    clrm++;
                    clrm%=k;
                }
                left-=clr[i].size();
            }
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
