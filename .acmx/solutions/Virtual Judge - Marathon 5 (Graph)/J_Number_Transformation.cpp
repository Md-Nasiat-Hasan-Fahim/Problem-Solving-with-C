#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
// #define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;
int ara[1010];
vector<int> pr;

void sieve()
{
    pr.pb(2);
    for (int i = 3; i < 1010; i += 2)
    {
        if (!ara[i])
        {
            pr.pb(i);
            for (int j = i * i; j < 1010; j += i + i)
                ara[j] = 1;
        }
    }
}

int  s, t;
vector<int> dp;

int dfs(int x)
{
    if (x > t)
        return -1;
    if (x == t)
        return dp[x]=0;
    if (dp[x])
        return dp[x];
    int step = INT_MAX;
    for (int i = 0; i < pr.size(); i++)
    {
        if (x % pr[i]==0&&pr[i]!=x)
        {
            int xy = dfs(pr[i] + x);
            if(xy!=-1) step = min(step, 1 + xy);
        }
    }
    if(step==INT_MAX) return dp[x]=-1;
    return dp[x] = step;
}

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA = 1;
    cin >> Master0fTheSEA;
    sieve();
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        cin >> s >> t;
        dp.assign(t + 1, 0);
        int ans = dfs(s);
        cout << "Case " << tttttttt << ": ";
        cout<<ans<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
