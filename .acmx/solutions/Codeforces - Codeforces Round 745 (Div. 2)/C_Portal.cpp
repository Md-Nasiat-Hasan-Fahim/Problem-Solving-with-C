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

vector<vector<int>>grid;
int n,m;

bool is_valid(int i, int j)
{
    return (i>0&&i<=n&&j>0&&j<=m);
}

int pqr(int i, int j, int x, int y)
{
    int cnt = grid[i-1][j-1]+grid[x][y];
    cnt-=(grid[i-1][y]+grid[x][j-1]);
    return cnt;
}


int abc(int i, int j, int x, int y)
{
    int cm = pqr(i+1,j+1,x-1,y-1);
    int cx1 = (y-1-j)-pqr(i,j+1,i,y-1);
    int cx2 = (y-1-j)-pqr(x,j+1,x,y-1);
    int cy1 = (x-1-i)-pqr(i+1,j,x-1,j);
    int cy2 = (x-1-i)-pqr(i+1,y,x-1,y);
    return cm+cx1+cx2+cy1+cy2;
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
        vector<string>vec;
        string tem = "";
        for(int i=0;i<=m;i++) tem.pb('#');
        vec.pb(tem);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            s = "#"+s;
            vec.pb(s);
        }
        int cnt = LONG_LONG_MAX;
        grid.assign(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                grid[i][j]=vec[i][j]-'0';
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=i-4;k>0;k--)
                {
                    for(int l = j-3;l>0;l--)
                    {
                        cnt = min(cnt,abc(k,l,i,j));
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
