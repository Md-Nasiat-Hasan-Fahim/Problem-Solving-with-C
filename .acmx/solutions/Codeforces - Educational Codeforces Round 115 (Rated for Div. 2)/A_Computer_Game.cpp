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

vector<pair<int,int>>mv = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n;

bool is_safe(int x, int y)
{
    return x>-1&&x<2&&y>-1&&y<n;
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
        cin>>n;
        vector<string>vec;
        string s;
        cin>>s;vec.pb(s);
        cin>>s;vec.pb(s);
        queue<pair<int,int>>q;
        q.push({0,0});
        int vis[4][102];
        memset(vis,0,sizeof(vis));
        while(!q.empty())
        {
            auto [fx,fy]=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                auto [x,y] = mv[i];
                if(is_safe(x+fx,y+fy)&&!vis[x+fx][y+fy]&&vec[x+fx][y+fy]!='1')
                {
                    q.push({x+fx,y+fy});
                    vis[x+fx][y+fy]=true;
                }
            }
        }
        if(vis[1][n-1]) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
