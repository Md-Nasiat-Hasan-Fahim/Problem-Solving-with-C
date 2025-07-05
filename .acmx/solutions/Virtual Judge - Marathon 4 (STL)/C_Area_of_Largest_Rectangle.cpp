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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,m;
        cin>>n>>m;
        int vec[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>vec[i][j];
        }
        int hi[n][m],wi[n][m];
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vec[i][j]==1)
                {
                    hi[i][j]=1;
                    wi[i][j]=1;
                    if(i-1>-1) hi[i][j]=max(hi[i][j],hi[i-1][j]+1);
                    if(j-1>-1) wi[i][j]=max(wi[i][j],wi[i][j-1]+1);
                }
                else hi[i][j]=wi[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mn = INT_MAX;
                int lmx = 0;
                for(int k=j;k>-1;k--)
                {
                    mn = min(mn,hi[i][k]);
                    lmx = max(lmx,((j-k+1)*mn));
                }
                mx = max(lmx,mx);
                //cout<<i<<" "<<j<<" "<<lmx<<endl;
            }
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
