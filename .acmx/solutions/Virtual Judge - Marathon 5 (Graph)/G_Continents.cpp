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
vector<vector<int>>vis;
vector<pair<int,int>>mv = {{1,0},{-1,0},{0,1},{0,-1}};
vector<string>vec;
int n,m;
int cnt;
char ch;

bool is_valid(int x, int y)
{
    return x<n&&x>-1&&y<m&&y>-1;
}

void dfs(int i, int j, int k)
{
    vis[i][j]=k;
    for(int p=0;p<4;p++)
    {
        int x = mv[p].first+i;
        int y = mv[p].second+j;
        y%=m;
        if(y<0) y+=m;
        if(is_valid(x,y)&&vec[x][y]==ch&&!vis[x][y]) cnt++,dfs(x,y,k);
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    while(cin>>n>>m)
    {
        vec.clear();
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
        }
        int k = 0;
        vis.assign(n+1,vector<int>(m+1));
        int mx = 0;
        int a,b;
        cin>>a>>b;
        ch = vec[a][b];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&vec[i][j]==ch)
                {
                    cnt = 1;
                    k++;
                    dfs(i,j,k);
                    if(k!=vis[a][b]) mx = max(mx,cnt);
                    //cout<<i<<" "<<j<<" "<<cnt<<endl;
                }
            }
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
