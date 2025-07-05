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
        vector<vector<int>>vec(n+1,vector<int>(m+1));
        vector<int>pos[m+1];
        int one = 0;
        for(int i=1;i<=n;i++)
        {
            int cnt = 0;
            for(int j=1;j<=m;j++)
            {
                int a;
                cin>>a;
                vec[i][j]=a;
                if(a==1) cnt++;
            }
            vec[i][0]=cnt;
            one+=cnt;
        }
        if(one%n!=0)
        {
            cout<<"-1\n";
            continue;
        }
        int p = one/n;
        int cnt = 0;
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(vec[i][0]<p) q.push(i);
            else if(vec[i][0]>p)
            {
                for(int j=1;j<=m;j++)
                {
                    if(vec[i][j]==1) pos[j].pb(i);
                }
            }
            cnt+=abs(p-vec[i][0]);
        }
        cout<<(cnt/2)<<endl;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int j=1;j<=m;j++)
            {
                if(vec[f][0]>=p) break;
                if(vec[f][j]==1) continue;
                while(pos[j].size()&&vec[pos[j].back()][0]<=p) pos[j].pop_back();
                if(pos[j].size())
                {
                    cout<<f<<" "<<pos[j].back()<<" "<<j<<endl;
                    vec[pos[j].back()][0]--;
                    vec[f][0]++;
                    pos[j].pop_back();
                }
                while(pos[j].size()&&vec[pos[j].back()][0]<=p) pos[j].pop_back();
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
