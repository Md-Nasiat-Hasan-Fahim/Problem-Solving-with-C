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
        vector<int> vec(n);
        vector<int> pos[3];
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            if (vec[i])
                pos[vec[i]].pb(i);
        }
        vector<int> vis(n + 1, 0);
        int cnt = 0;
        for (int k = 0; k < pos[2].size(); k++)
        {
            int i = pos[2][k];
            if (vis[i])
                continue;
            for (int j = i; j > -1; j--)
            {
                if (j == 0 || vec[j] == 0 || vis[j] == 1)
                {
                    vis[j] = true;
                    break;
                }
                vis[j] = true;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (j == n - 1 || vec[j] == 0 || vis[j] == 1)
                {
                    vis[j] = true;
                    break;
                }
                vis[j] = true;
            }
            cnt++;
        }
        // cout<<cnt<<endl;

        for (int k = 0; k < pos[1].size(); k++)
        {
            int i = pos[1][k];
            if (vis[i])
                continue;
            int ct1 = 0, ct2 = 0;
            vis[i] = true;
            int fg1 = 0, fg2 = 0;
            for (int j = i - 1; j > -1; j--)
            {
                ct1++;
                if (j == 0 || vis[j] == 1 || vec[j] == 0)
                {
                    if (j == 0 && vec[j] != 0)
                        fg1 = 1;
                    ct1-=vis[j];
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                ct2++;
                if (j == n - 1 || vis[j] == 1 || vec[j] == 0)
                {
                    if (j == n - 1 && vec[j] != 0)
                        fg2 = 1;
                    ct2-=vis[j];
                    break;
                }
            }
            // cout<<i<<" "<<fg1<<" "<<fg2<<endl;
            if (fg1)
            {
                for (int j = 0; j < n; j++)
                {
                    vis[j] = true;
                    if (vec[j] == 0)
                    {
                        break;
                    }
                }
            }
            else if (fg2)
            {
                for (int j = n - 1; j > -1; j--)
                {
                    vis[j] = true;
                    // cout<<j<<" "<<vec[j]<<endl;
                    if (vec[j] == 0)
                        break;
                }
            }
            else if (ct1 > ct2)
            {
                for (int j = i; j > -1; j--)
                {
                    vis[j] = true;
                    if (j == 0 || vis[j] == 1 || vec[j] == 0)
                    {
                        vis[j] = true;
                        break;
                    }
                }
            }
            else
            {
                for (int j = i; j < n; j++)
                {
                    if (j == n - 1 || vis[j] == 1 || vec[j] == 0)
                    {
                        vis[j] = true;
                        break;
                    }
                    vis[j] = true;
                }
            }
            cnt++;
            cout<<ct1<<" "<<ct2<<endl;
            for (int i = 0; i < n; i++)
                cout << i << " " << vis[i] << endl;
            cout << endl
                 << endl;
        }
        for (int i = 0; i < n; i++)
            cnt += (!vis[i]);
        cout << cnt << endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
