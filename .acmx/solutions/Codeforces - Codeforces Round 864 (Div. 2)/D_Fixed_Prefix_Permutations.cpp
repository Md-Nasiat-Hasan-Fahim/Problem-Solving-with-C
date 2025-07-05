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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>vec[n];
        vector<int>cnt[m+1][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a;
                cin>>a;
                vec[i].pb(a);
                cnt[j+1][a].pb(i);
            }
        }
        int dp[n]={0};
        for(int i=0;i<n;i++)
        {
            int mx = 0;
            int c = 1;
            queue<int>q;
            int mn = INT_MAX;
            for(int j=0;j<m;j++)
            {
                int x = vec[i][j];
                for(int tc=1;tc<=m;tc++)
                {
                    mn = min(mn,(int)cnt[x][tc].size());
                }
            }
            for(int j=0;j<m;j++,c++)
            {
                int y = mx;
                int x = vec[i][j];
                if(j==0)
                {
                    for(int k=0;k<cnt[x][c].size();k++)
                    {
                        dp[cnt[x][c][k]]++;
                        mx = 1;
                        q.push(cnt[x][c][k]);
                    }
                }
                else
                {
                    for(int k=0;k<cnt[x][c].size();k++)
                    {
                        if(dp[cnt[x][c][k]])
                        {
                            dp[cnt[x][c][k]]++;
                        }
                        if(dp[cnt[x][c][k]]==c) mx = max(mx,dp[cnt[x][c][k]]);
                    }
                }
                if(y==mx) break;
            }
            cout<<mx<<" ";
            while(!q.empty())
            {
                dp[q.front()]=0;
                q.pop();
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}