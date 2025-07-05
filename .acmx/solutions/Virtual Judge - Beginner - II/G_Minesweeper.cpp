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

vector<pair<int,int>> move = {{1,1},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1},{-1,-1}};
int n,m;
bool is_valid(int x, int y)
{
    return x<n&&x>-1&&y<m&&y>-1;
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>m;
        if(n==0&&m==0) break;
        vector<vector<int>>ans(n+1,vector<int>(m+1));
        vector<string>inp;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            inp.push_back(s);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k< move.size();k++)
                {
                    if(is_valid(i+move[k].first,j+move[k].second))
                    {
                        if(inp[i+move[k].first][j+move[k].second]=='*')
                        ans[i+move[k].first][j+move[k].second]++;
                    }
                }
            }
        }
        cout<<"Field "<<"#"<<z<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
