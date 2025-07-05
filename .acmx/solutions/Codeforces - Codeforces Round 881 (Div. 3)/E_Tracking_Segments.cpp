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
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>meet(n+1,0),cum(n+1,0);
        queue<pair<int,int>>q;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            q.push({a,b});
        }
        int tme = 0;
        int qr;
        cin>>qr;
        for(int i=0;i<qr;i++)
        {
            int a;
            cin>>a;
            if(!meet[a])
            {
                meet[a]=++tme;
                cum[a]=1;
            }
        }
        for(int i=1;i<=n;i++) cum[i]+=cum[i-1];
        int rmq[n+1][32];
        memset(rmq,0,sizeof(rmq));
        for(int i=0;i<=n;i++) rmq[i][0]=meet[i];
        for(int j=1;j<32;j++)
        {
            int y = 1<<(j-1);
            if(y+1>n) break;
            for(int i=1;i<=n;i++)
            {
                if(i+y+1<=n)
                rmq[i][j]=max(rmq[i][j-1],rmq[i+y+1][j-1]);
            }
        }
        int mn = LONG_LONG_MAX;
        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            int p = cum[b]-cum[a-1];
            int x = b-a+1;
            //cout<<a<<" "<<b<<" "<<p<<endl;
            if(p<((x/2)+1)) {continue;}
            int y=0;
            for(int i=0;i<32;i++)
            {
                if((1LL<<i)<x) y = i;
            }
            mn = min({mn,max(rmq[a][y],rmq[b-(1LL<<y)+1][y])});
            cout<<y<<" "<<a<<" "<<b-(1LL<<y)+1<<" ";
            cout<<rmq[a][y]<<" "<<rmq[b-(1LL<<y)+1][y]<<endl;
            //cout<<mn<<endl;
        }
        cout<<rmq[3][1]<<endl;
        if(mn==LONG_LONG_MAX) cout<<"-1\n";
        else cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
