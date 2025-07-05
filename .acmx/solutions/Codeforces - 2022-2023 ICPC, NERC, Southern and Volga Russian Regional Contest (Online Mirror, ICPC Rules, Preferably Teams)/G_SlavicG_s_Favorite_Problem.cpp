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
const int mx = 1e5+5;

vector<pair<int,int>>graph[mx];
vector<int>vis;
multiset<int>st[2];
int a,b;

void bfs(int s, int y)
{
    vis[s]=0;
    queue<int>q;
    q.push(s);
    int x = 0;
    while(!q.empty())
    {
        int f = q.front();
        x = vis[f];
        q.pop();
        for(auto c : graph[f])
        {
            if(vis[c.first]!=-1||c.first==b) continue;
            q.push(c.first);
            //cout<<(x^c.second)<<" "<<c.first<<endl;
            st[y].insert((x^c.second));
            vis[c.first]=(x^c.second);
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        while(st[0].size()) st[0].erase(st[0].begin());
        while(st[1].size()) st[1].erase(st[1].begin());
        for(int i=0;i<mx;i++) graph[i].clear();
        int n;
        cin>>n>>a>>b;
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].pb({v,w});
            graph[v].pb({u,w});
        }
        vis.assign(n+1,-1);
        bfs(b,0);
        vis.assign(n+1,-1);
        bfs(a,1);
        bool ans = false;
        //cout<<st[0].size()<<" "<<st[1].size()<<endl;
        while(!st[0].empty())
        {
            //cout<<*st[0].begin()<<endl;
            if(st[1].count(*st[0].begin())||(*st[0].begin()==0))
            {
                ans = true;
                break;
            }
            st[0].erase(st[0].begin());
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
