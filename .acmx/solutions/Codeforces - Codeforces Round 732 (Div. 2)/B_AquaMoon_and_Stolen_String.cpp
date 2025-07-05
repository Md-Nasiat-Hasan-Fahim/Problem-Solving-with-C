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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<string>vec;
        vector<string>arg;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
        }
        for(int i=0;i<n-1;i++)
        {
            string s;
            cin>>s;
            arg.pb(s);
        }
        int cnt1[m]['z'+1],cnt2[m]['z'+1];
        memset(cnt1,0,sizeof(cnt1));memset(cnt2,0,sizeof(cnt2));
        for(int j=0;j<m;j++)
        {
            int tem['z'+1]={0};
            for(int i=0;i<n;i++)
            {
                tem[vec[i][j]]++;
            }
            for(int i='a';i<='z';i++)
            {
                cnt1[j][i]=tem[i];
            }
        }
        for(int j=0;j<m;j++)
        {
            int tem['z'+1]={0};
            for(int i=0;i<n-1;i++)
            {
                tem[arg[i][j]]++;
            }
            for(int i='a';i<='z';i++)
            {
                cnt2[j][i]=tem[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            bool ans = true;
            for(int j=0;j<m;j++)
            {
                for(int k='a';k<='z';k++)
                {
                    if(cnt1[j][k]-(vec[i][j]==k)!=cnt2[j][k]) ans = false;
                }
            }
            if(ans)
            {
                cout<<vec[i]<<endl;
                break;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
