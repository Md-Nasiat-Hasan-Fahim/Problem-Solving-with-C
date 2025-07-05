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
vector<string>graph;
vector<vector<int>>vec;
vector<pair<int,int>>mv={{1,0},{-1,0},{0,1},{0,-1}};
int ans;
int n,m;

bool is_valid(int x, int y)
{
    return x>-1&&x<n&&y>-1&&y<m;
}

void dfs(int x,int y, int mark)
{
    vec[x][y]=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty())
    {
        auto [fx,fy]=q.front();
        if(mark&&(fx==0||fy==0||fx==n-1||fy==m-1)) ans = min(vec[fx][fy],ans);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = fx + mv[i].first;
            int y1 = fy + mv[i].second;
            if(is_valid(x1,y1)&&graph[x1][y1]!='#'&&vec[fx][fy]+1<vec[x1][y1])
            {
                vec[x1][y1]=vec[fx][fy]+1;
                q.push({x1,y1});
            }
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    // FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>n>>m;
        ans = mod;
        vec.assign(n+1,vector<int>(m+1,mod));
        graph.assign(n+1,"");
        for(int i=0;i<n;i++)
        {
            cin>>graph[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(graph[i][j]=='F') dfs(i,j,0);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(graph[i][j]=='J') dfs(i,j,1);
            }
        }
        cout<<"Case "<<tttttttt<<": ";
        if(ans!=mod) cout<<ans+1<<endl;
        else cout<<"IMPOSSIBLE\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
