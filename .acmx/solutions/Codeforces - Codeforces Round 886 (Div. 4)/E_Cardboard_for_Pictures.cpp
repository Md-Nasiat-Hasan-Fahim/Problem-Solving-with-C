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

void dfs(vector<vector<int>> &tree, int node, int &now, int m, int iter)
{
    if (!tree[node][0] && !tree[node][1] || iter == -1)
        return;
    if (((1 << iter) & m))
    {
        if (tree[node][0])
        {
            dfs(tree, tree[node][0], now, m, iter - 1);
        }
        else
        {
            now |= (1 << iter);
            dfs(tree, tree[node][1], now, m, iter - 1);
        }
    }
    else
    {
        if (tree[node][1])
        {
            now |= (1 << iter);
            dfs(tree, tree[node][1], now, m, iter - 1);
        }
        else
        {
            dfs(tree, tree[node][0], now, m, iter - 1);
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
        int pq = 0;
        cin>>pq;
        vector<int>nums(pq);
        for(int i=0;i<pq;i++) cin>>nums[i];
        int n = nums.size();
        vector<vector<int>>tree;
        tree.push_back(vector<int>(2));
        int m;
        int node = 0;
        for(int i=0;i<n;i++)
        {
            m = 0;
            for(int j=30;j>-1;j--)
            {
                if(((1<<j)&nums[i]))
                {
                    if(!tree[m][1]) node++,tree.push_back(vector<int>(2)),tree[m][1]=node;
                    m = tree[m][1];
                }
                else
                {
                    if(!tree[m][0]) node++,tree.push_back(vector<int>(2)),tree[m][0]=node;
                    m = tree[m][0];
                }
            }
        }
        int mx = 0;
        int now = 0;
        for(int i=0;i<n;i++)
        {
            now = 0;
            dfs(tree,0,now,nums[i],30);
            cout<<nums[i]<<" "<<now<<" "<<(now^nums[i])<<endl;
            mx = max(mx,(now^nums[i]));
        }
        cout<<mx<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
