#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

vector<pair<int,int>>mv = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>>dis,fire;
int n,m;

bool is_valid(int x, int y)
{
    return x>-1&&x<n&&y>-1&&y<m;
}

void bfs1(int x, int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    fire[x][y]=0;
    while(!q.empty())
    {
        auto [fi,fj] = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci = fi + mv[i].first;
            int cj = fj + mv[i].second;
            if(is_valid(ci,cj)&&dis[ci][cj]!=INT_MAX&&fire[fi][fj]+1<fire[ci][cj])
            {
                fire[ci][cj]=fire[fi][fj]+1;
                q.push({ci,cj});
            }
        }
    }
}

void bfs2(int x, int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    dis[x][y]=0;
    int p = 100;
    while(!q.empty()&&p--)
    {
        auto [fi,fj] = q.front();
        cout<<fi<<" "<<fj<<endl;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int j = fi + mv[i].first;
            int k = fj + mv[i].second;
            if(is_valid(j,k)&&dis[j][k]!=INT_MAX&&dis[fi][fj]+1<fire[j][k])
            {
                dis[j][k]=dis[fi][fj]+1;
                q.push({j,k});
            }
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>n>>m;
        dis.assign(n+1,vector<int>(m+1,INT_MAX));
        fire.assign(n+1,vector<int>(m+1,INT_MAX));
        int jx,jy;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='.') dis[i][j]=-1;
                else if(s[j]=='J')
                {
                    jx = i, jy = j;
                }
                else if(s[j]=='F')
                {
                    dis[i][j]=50000;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dis[i][j]==50000) bfs1(i,j);
            }
        }
        bfs2(jx,jy);
        int mn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(dis[i][j]!=-1&&dis[i][j]<fire[i][j]) mn = min(mn,dis[i][j]);
                    //cout<<dis[i][j]<<" "<<fire[i][j]<<" "<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<"Case "<<tttttttt<<": ";
        if(mn!=INT_MAX) cout<<mn+1<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
