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

vector<vector<int>>graph1,graph2;

int n1,n2;

int bfs(int s)
{
    queue<int>q;
    vector<int>level;
    auto graph = graph1;
    if(s==1)
    {
        q.push(1);
        level.assign(n1+1,-1);
        level[1]=0;
    }
    else 
    {
        q.push(n1+n2);
        level.assign(n1+n2+1,-1);
        level[n1+n2]=0;
        graph = graph2;
    }
    int mx = 0;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(auto c : graph[f])
        {
            //cout<<c<<" "<<f<<endl;
            if(level[c]!=-1) continue;
            level[c]=level[f]+1;
            mx = max(mx,level[c]);
            q.push(c);
        }
    }
    cout<<endl;
    return mx;
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
        int m;
        cin>>n1>>n2>>m;
        graph1.assign(n1+1,vector<int>());
        graph2.assign(n1+n2+1,vector<int>());
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>n1)
            {
                graph2[a].pb(b);
                graph2[b].pb(a);
            }
            else
            {
                graph1[a].pb(b);
                graph1[b].pb(a);
            }
        }
        cout<<bfs(n1+n2)+bfs(1)+1<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
