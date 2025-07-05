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

int ans;

void dfs(int x,vector<int> &vis, vector<vector<int>>&vec,stack<int>&st)
{
    vis[x]=-1;
    for(auto c:vec[x])
    {
        if(!vis[c]) dfs(c,vis,vec,st);
        else
        {
            if(vis[c]==-1)
            {
                ans = -1;
            }
        }
    }
    vis[x]=1;
    st.push(x);
    return;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>vec(n+1,vector<int>());
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].pb(v);
        }
        vector<int>vis(n+1);
        stack<int>st1,st2;
        for(int i=n;i>0;i--)
        {
            if(!vis[i]) dfs(i,vis,vec,st1);
        }
        if(ans==-1) cout<<"Sandro fails.";
        else
        {
            int deg[n+1]={0};
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<vec[i].size();j++)
                {
                    deg[vec[i][j]]++;
                }
            }
            set<int>st;
            for(int i=1;i<=n;i++)
            {
                if(deg[i]==0) st.insert(i);
            }
            while(!st.empty())
            {
                int a = *st.begin();
                st.erase(st.begin());
                cout<<a<<" ";
                for(int j=0;j<vec[a].size();j++)
                {
                    deg[vec[a][j]]--;
                    if(deg[vec[a][j]]==0) st.insert(vec[a][j]);
                }
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
