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
        vector<int> vec(n);
        vector<int> sec, pos;
        int ara[n] = {0};
        int sum = 0;
        int tem[n + 1] = {0};
        int one = 0;
        int cn = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            if (vec[i])
                sec.pb(vec[i]), pos.pb(i), tem[vec[i]] = 1, sum += vec[i];
            if (vec[i] == 1)
                one++;
        }
        bool falg = true;
        for (int i = 1; i <= sec.size(); i++)
        {
            if (!tem[i])
            {
                falg = false;
            }
            if (sec[i-1] == sec.size())
                cn++;
        }
        bool ans = false;
        //cout<<cn<<" "<<sec.size()<<endl;
        if (cn == sec.size())
        {
            ans = true;
            for (int i = 0; i < sec.size(); i++)
            {
                if (sec[i] == sec.size())
                    ara[pos[i]] = 1;
            }
        }
        else if ((sum == ((sec.size() * (sec.size() + 1)) / 2)) && falg)
        {
            ans = true;
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < sec.size(); i++)
                pq.push({sec[i], pos[i]});
            int cp = sec.size();
            while (!pq.empty())
            {
                ara[pq.top().second] = cp;
                pq.pop();
                cp -= 2;
                if (cp == 0)
                    cp--;
            }
        }
        else if (one >= sec.size() - 1 && sum == (2 * sec.size() - 1))
        {
            ans = true;
            for (int i = 0; i < sec.size(); i++)
            {
                if (sec[i] == 1)
                    ara[pos[i]] = -1;
                else
                    ara[pos[i]] = sec.size();
            }
        }
        if (ans)
        {
            YES;
            for (int i = 0; i < n; i++)
                if (ara[i])
                    cout << ara[i] << " ";
                else
                    cout << -n << " ";
            cout << endl;
        }
        else
            NO;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
