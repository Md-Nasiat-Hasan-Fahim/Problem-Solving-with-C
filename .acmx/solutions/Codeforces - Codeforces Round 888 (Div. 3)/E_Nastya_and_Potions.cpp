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
stack<int>stc;
vector<int>vis;

void dfs(int x)
{
    vis[x]=true;
    for(auto c : graph[x])
    {
        if(vis[c]) continue;
        dfs(c);
    }
    stc.push(x);
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
        int n,k;
        cin>>n>>k;
        vector<int>val(n+1);
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        vector<int>vec[n+1];
        for(int i=1;i<=n;i++) cin>>val[i];
        set<int>st;
        for(int i=0;i<k;i++)
        {
            int a;
            cin>>a;
            st.insert(a);
        }
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            for(int j=0;j<a;j++)
            {
                int b;
                cin>>b;
                vec[i].pb(b);
                if(st.count(b)) continue;
                graph[b].pb(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) dfs(i);
        }
        vector<int>cntc(n+2);
        //cout<<stc.size()<<endl;
        while(!stc.empty())
        {
            int x = stc.top();
            stc.pop();
            if(st.count(x))
            {
                cntc[x]=0;
                continue;
            }
            else
            {
                int ct = 0;
                if(vec[x].size()==0)
                {
                    cntc[x]=val[x];
                    continue;
                }
                for(int i=0;i<vec[x].size();i++)
                {
                    if(st.count(vec[x][i])) ct+=0;
                    else ct+=cntc[vec[x][i]];
                }
                cntc[x]=min(ct,val[x]);
            }
            //cout<<x<<" "<<cntc[x]<<" "<<val[x]<<endl;
        }
        for(int i=1;i<=n;i++) cout<<cntc[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
