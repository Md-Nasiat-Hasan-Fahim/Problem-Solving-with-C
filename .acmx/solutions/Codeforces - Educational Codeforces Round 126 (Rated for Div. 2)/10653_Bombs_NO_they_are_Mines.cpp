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
vector<vector<int>> level;
int r,c;

bool is_valid(int x, int y)
{
    return x>-1&&x<r&&y>-1&&y<c;
}

vector<pair<int,int>>mv = {{0,1},{1,0},{0,-1},{-1,0}};


void bfs(int sx, int sy)
{
    level[sx][sy]=0;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    while(!q.empty())
    {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = fx+mv[i].first;
            int y = fy+mv[i].second;
            if(is_valid(x,y)&&level[x][y]==-1&&graph[x][y]!=1)
            {
                level[x][y]=level[fx][fy]+1;
                q.push({x,y});
            }
        }
    }
}

signed main()
{
    FastIO;
    int t=1;
    //cin>>t;
    while(1)
    {
        cin>>r>>c;
        if(r==0&&c==0) break;
        graph.assign(r,vector<int>(c));
        level.assign(r,vector<int>(c,-1));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            int m;
            cin>>m;
            for(int i=0;i<m;i++)
            {
                int x;
                cin>>x;
                graph[a][x]=1;
            }
        }
        int sx,sy;
        cin>>sx>>sy;
        int dx,dy;
        cin>>dx>>dy;
        bfs(sx,sy);
        cout<<level[dx][dy]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
