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
const int inf = 1e12;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

vector<vector<int>>val1,val2;
vector<pair<int,int>>mv = {{1,0},{0,1},{-1,0},{0,-1}};
int dp[505][505][22];
int tx,ty;
int n,m;

bool is_valid(int x, int y)
{
    return x>-1&&x<n&&y>-1&&y<m;
}

int abc(int i, int j, int k)
{
    if(k<=0)
    {
        if(k==0) return 0;
        else return inf;
    }
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int cnt = inf;
    for(int p = 0;p<mv.size();p++)
    {
        if(is_valid(i+mv[p].first,j+mv[p].second))
        {
            if(i+mv[p].first==i)
            {
                int px = max(j,j+mv[p].second);
                cnt=min(cnt,2*val1[i][px]+abc(i+mv[p].first,j+mv[p].second,k-2));
            }
            else
            {
                int px = max(i,i+mv[p].first);
                cnt = min(cnt,2*val2[px][j]+abc(i+mv[p].first,j+mv[p].second,k-2));
            }
        }
    }
    dp[i][j][k] = cnt;
    return cnt;
}

signed main()
{
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        memset(dp,-1,sizeof(dp));
        int k;
        cin>>n>>m>>k;
        val1.assign(n+1,vector<int>(m+1));
        val2.assign(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int a;
                cin>>a;
                val1[i][j]=a;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a;
                cin>>a;
                val2[i][j]=a;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                tx = i;
                ty = j;
                int cnt = abc(tx,ty,k);
                if(cnt!=inf)
                cout<<cnt<<" ";
                else cout<<"-1 ";
            }
            cout<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
