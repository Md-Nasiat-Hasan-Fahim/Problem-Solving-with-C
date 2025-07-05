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
vector<int>vis;

void dfs(int x)
{
    vis[x]=1;
    for(auto c:graph[x])
    {
        dfs(c);
    }
    st.push(x);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        int mtx[n+1][n+1];
        memset(mtx,0,sizeof(mtx));
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cout<<"? ";
            for(int j=1;j<=n;j++)
            {
                if(j==i) cout<<"1 ";
                else cout<<"0 ";
            }
            cout<<endl;
            int x;
            cin>>x;
            if(x!=0&&x!=i)
            {
                if(!mtx[i][x])
                {
                    mtx[i][x]=1;
                    graph[i].pb(x);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<"? ";
            for(int j=1;j<=n;j++)
            {
                if(j==i) cout<<"-1 ";
                else cout<<"0 ";
            }
            cout<<endl;
            int x;
            cin>>x;
            if(x!=0&&x!=i)
            {
                if(!mtx[x][i])
                {
                    mtx[x][i]=1;
                    graph[x].pb(i);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) dfs(i);
        }
        int ara[n+1];
        int cnt=1;
        while(!st.empty())
        {
            ara[st.top()]=cnt++;
            st.pop();
        }
        for(int i=1;i<=n;i++) cout<<ara[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
