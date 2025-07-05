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
vector<int>graph[100000+7];
vector<pair<int,int>>val;
vector<bool>vis;
vector<int>level;

int bfs(int s)
{
    YES;
    queue<int>q;
    q.push(s);
    vis[s]=true;
    level[s]=val[s].first;
    int cnt = 0;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(auto c : graph[f])
        {
            if(vis[c]) continue;
            int x = abs(level[f]-val[c].first);
            int y = abs(level[f]-val[c].second);
            if(x>y) {level[c]=val[c].first;cnt+=x;}
            else {level[c]=val[c].second;cnt+=y;}
            vis[c]=true;
            q.push(c);
        }
    }
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        val.assign(n+1,{0,0});
        for(int i=0;i<=n+1;i++) graph[i].clear();
        level.assign(n+1,0);
        vis.assign(n+1,false);
        int l,mn = LONG_LONG_MAX;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            val[i]={a,b};
            if(a<mn)
            {
                mn = a;
                l = i;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            cout<<a<<" "<<b<<endl;
            YES;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        //graph[1].pb(2);
        //graph[2].pb(1);
        YES;
        cout<<bfs(l)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
