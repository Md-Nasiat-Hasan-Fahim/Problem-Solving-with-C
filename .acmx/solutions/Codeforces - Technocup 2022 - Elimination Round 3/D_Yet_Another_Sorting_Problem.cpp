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

bool ans;
int m;

void abc(int fg, vector<int> vec, int cnt)
{
    if (fg == ((1 << m) - 1) || cnt == 3)
    {
        int flag = true;
        for (int i = 0; i < m - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = true;
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (!(fg & (1 << i)))
        {
            for (int j = 0; j < m; j++)
            {
                if (!(fg & (1 << j)))
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (!(fg & (1 << k)))
                        {
                            int tf = fg;
                            vector<int> pq;
                            pq = {i, j, k};
                            for (int l = 0; l < 3; l++)
                            {
                                tf |= (1 << pq[l]);
                            }
                            vector<int> ab;
                            for (int i = 0; i < pq.size(); i++)
                            {
                                ab.pb(vec[pq[i]]);
                            }
                            while (1)
                            {
                                for (int i = 0; i < pq.size(); i++)
                                {
                                    vec[pq[i]] = ab[i];
                                }
                                abc(tf, vec, cnt + 1);
                                if (!next_permutation(all(ab)))
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
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
        ans = false;
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];
        auto tem = vec;
        sort(all(tem));
        vector<int> ab;
        for (int i = 0; i < n; i++)
        {
            if (tem[i] != vec[i])
                ab.pb(vec[i]);
        }
        m = ab.size();
        // cout<<m<<endl;
        if (vec.size() > 9 || m < 3)
        {
            NO;
            continue;
        }
        abc(0, ab, 0);
        if (ans)
            YES;
        else
            NO;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
