#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;

void abc(int x, vector<int> &vec)
{
    int i;
    for (i = 1; i*i < x; i++)
    {
        if (x % i == 0)
            vec.pb(i), vec.pb(x / i);
    }
    if(i*i==x) vec.pb(i);
}

struct PairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &v) const
    {
        return std::hash<T1>()(v.first) ^ hash<T2>()(v.second) << 1;    
        //return std::hash<T1>{}(v.first) ^ hash<T2>{}(v.second) << 1;    //same as above
    }
};

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
        string s;
        cin >> n >> s;
        s = "#" + s;
        unordered_map<pair<int, int>, int, PairHash> pre, precnt;
        int cntd[n + 1] = {0}, cntk[n + 1] = {0};
        for (int i = 1; i <= n; i++)
        {
            int mx = -1;
            cntd[i] = cntd[i - 1] + (s[i] == 'D');
            cntk[i] = cntk[i - 1] + (s[i] == 'K');
            vector<int> div;
            abc(__gcd(cntd[i],cntk[i]), div);
            if (cntd[i] == 0)
            {
                mx = max(mx, i);
                pre[{0, 1}] = i;
                precnt[{0, 1}] = i;
            }
            else if (cntk[i] == 0)
            {
                mx = max(mx, i);
                pre[{1, 0}] = i;
                precnt[{1, 0}] = i;
            }
            else
            {
                for (int j = 0; j < div.size(); j++)
                {
                    if (cntk[i] % div[j] == 0)
                    {
                        int x = cntd[i] / div[j];
                        int y = cntk[i] / div[j];
                        int z = pre[{x, y}];
                        if (z)
                        {
                            int ctd = cntd[i] - cntd[z];
                            int ctk = cntk[i] - cntk[z];
                            if (ctd % x == 0 && ctk % y == 0)
                            {
                                pre[{x, y}] = i;
                                precnt[{x, y}]++;
                                mx = max(mx, precnt[{x, y}]);
                            }
                        }
                        else
                        {
                            pre[{x, y}] = i;
                            precnt[{x, y}]++;
                        }
                    }
                }
            }
            mx = max(1, mx);
            if (pre[{cntd[i], cntk[i]}] < 1)
            {
                pre[{cntd[i], cntk[i]}] = i;
                precnt[{cntd[i], cntk[i]}] = 1;
            }
            cout << mx << " ";
        }
        cout << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
