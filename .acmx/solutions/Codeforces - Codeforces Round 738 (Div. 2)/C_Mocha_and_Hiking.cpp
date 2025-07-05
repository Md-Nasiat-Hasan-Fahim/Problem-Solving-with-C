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
vector<int>vis;
stack<int>st;

void dfs(int x)
{
    vis[x]=true;
    for(auto c:graph[x])
    {
        if(vis[c]) continue;
        dfs(c);
    }
    st.push(x);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        graph.assign(n+2,vector<int>());
        vis.assign(n+2,0);
        for(int i=1;i<n;i++)
        {
            graph[i].pb(i+1);
        }
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                graph[i+1].pb(n+1);
            }
            else
            {
                graph[n+1].pb(i+1);
            }
        }
        int cnt = 0;
        for(int i=1;i<=n+1;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i);
            }
        }
        if(cnt==1)
        {
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
        }
        else
        {
            vis.assign(n+2,0);
            while(st.size()) st.pop();
            dfs(n+1);
            cnt = 0;
            for(int i=1;i<=n+1;i++)cnt+=vis[i];
            if(cnt==n+1)
            {
                while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
            }
            else cout<<"-1\n";
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
