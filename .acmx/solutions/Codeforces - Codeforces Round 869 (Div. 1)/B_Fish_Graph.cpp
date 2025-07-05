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

int flag;
bool abc;

void dfs1(int s,int f)
{
    vis[s]=true;
    for(auto c:graph[s])
    {
        if(c==f) continue;
        if(vis[c])
        {
            if(c==flag)
            {
                abc = true;
            }
            return;
        }
        dfs1(c,s);
        if(abc) return;
    }
}

queue<pair<int,int>>qu;

void dfs2(int s,int f)
{
    vis[s]=true;
    for(auto c:graph[s])
    {
        if(c==f) continue;
        if(vis[c])
        {
            if(c==flag)
            {
                qu.push({c,s});
                abc = true;
            }
            return;
        }
        dfs2(c,s);
        if(abc) 
        {
            qu.push({c,s});
            return;
        }
    }
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
        int n,m;
        cin>>n>>m;
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        flag = false;
        abc = false;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        bool ans = false;
        for(int i=1;i<=n;i++)
        {
            flag = i;
            if(graph[i].size()>3)
            {
                for(int j=0;j<graph[i].size();j++)
                {
                    abc = false;
                    vis.assign(n+1,0);
                    vis[i]=true;
                    dfs1(graph[i][j],i);
                    int xyz = 0;
                    for(int k=0;k<graph[i].size();k++)
                    {
                        if(!vis[graph[i][k]]) xyz++;
                    }
                    if(abc&&xyz>1)
                    {
                        //cout<<i<<" "<<graph[i][j]<<" "<<abc<<" "<<xyz<<endl;
                        vis.assign(n+1,0);
                        abc=false;
                        vis[i]=true;
                        qu.push({graph[i][j],i});
                        dfs2(graph[i][j],i);
                        int a=-1,b=-1;
                        for(int k=0;k<graph[i].size();k++)
                        {
                            if(!vis[graph[i][k]])
                            {
                                if(a==-1) a=graph[i][k];
                                else if(b==-1) b = graph[i][k];
                                else break;
                            }
                        }
                        qu.push({i,a});
                        qu.push({i,b});
                        ans = true;
                        break;
                    }
                }
                if(ans) break;
            }
            if(ans) break;
        }
        if(ans)
        {
            YES;
            cout<<qu.size()<<endl;
            while(!qu.empty())
            {
                cout<<qu.front().first<<" "<<qu.front().second<<endl;
                qu.pop();
            }
        }
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
