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
stack<int>st;
vector<vector<int>>graph;
vector<bool>vis;

void dfs1(int s)
{
    vis[s]=true;
    for(auto c: graph[s])
    if(!vis[c]) dfs1(c);
    st.push(s);
}

void dfs2(int s)
{
    vis[s] = true;
    for(auto c: graph[s])
    if(!vis[c]) dfs2(c);
}

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        int n,m;
        cin>>n>>m;
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,false);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            dfs1(i);
        }
        vis.assign(n+1,false);
        int cnt = 0;
        while(!st.empty())
        {
            if(!vis[st.top()])
            {
                cnt++;
                dfs2(st.top());
            }
            st.pop();
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
