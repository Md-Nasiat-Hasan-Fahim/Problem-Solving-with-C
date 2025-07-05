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
        string s;
        cin >> s;
        stack<int> q;
        bool ans = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                q.push(s[i]);
            else
            {
                //cout<<(char)q.front()<<endl;
                if ((q.empty()))
                {
                    ans = false;
                }
                else
                {
                    if (s[i] == ')')
                    {
                        if (q.top() == '(')
                            q.pop();
                        else
                            ans = false;
                    }
                    if (s[i] == '}')
                    {
                        if (q.top() == '{')
                            q.pop();
                        else
                            ans = false;
                    }
                    if (s[i] == ']')
                    {
                        if (q.top() == '[')
                            q.pop();
                        else
                            ans = false;
                    }
                }
            }
        }
        //cout << ans << " " << q.size() << endl;
        if (ans && q.size() == 0)
            YES;
        else
            NO;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
