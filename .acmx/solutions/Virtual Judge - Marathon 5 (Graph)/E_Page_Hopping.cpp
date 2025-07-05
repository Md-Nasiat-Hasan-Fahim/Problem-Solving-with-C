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
    for(int tttttttt=1;1;tttttttt++)
    {
        vector<vector<int>>vec(101,vector<int>(101,INT_MAX));
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0) break;
        //cout<<a<<b<<endl;
        while(a!=0&&b!=0)
        {
            vec[a][b]=1;
            cin>>a>>b;
        }
        for(int i=0;i<101;i++)
        {
            vec[i][i]=0;
        }
        for(int k=1;k<101;k++)
        {
            for(int i = 1;i<101;i++)
            {
                for(int j=1;j<101;j++) vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
            }
        }
        double ab=0,cnt = 0;
        for(int i=1;i<101;i++)
        {
            for(int j=1;j<101;j++)
            {
                if(vec[i][j]!=INT_MAX&&i!=j)
                {
                    ab++;
                    cnt+=vec[i][j];
                    //cout<<vec[i][j]<<endl;
                } 
            }
        }
        double ans = cnt/ab;
        printf("Case %lld: average length between pages = %.3lf clicks\n",tttttttt,ans);
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
