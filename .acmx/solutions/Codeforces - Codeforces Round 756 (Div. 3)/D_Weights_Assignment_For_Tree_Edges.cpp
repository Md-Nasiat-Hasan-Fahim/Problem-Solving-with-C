#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

vector<vector<int>>graph;
vector<int>pos,ass;

bool ans;

void dfs(int s, int f)
{
    for(auto c: graph[s])
    {
        if(c==f) continue;
        if(pos[c]<pos[s]) ans = false;
        ass[c]=pos[c]-pos[s];
        dfs(c,s);
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        ans = true;
        int n;
        cin>>n;
        graph.assign(n+1,vector<int>());
        ass.assign(n+1,0);
        pos.assign(n+1,0);
        int root = -1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a==i+1)
            {
                root = a;
            }
            else graph[a].pb(i+1);
        }
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            pos[a]=i;
        }
        dfs(root,root);
        if(ans)
        {
            for(int i=1;i<=n;i++) cout<<ass[i]<<" ";
            cout<<endl;
        }
        else cout<<"-1\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
