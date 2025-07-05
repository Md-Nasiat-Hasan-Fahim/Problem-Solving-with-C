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
int n,m;

bool is_valid(int x, int y)
{
    return x>0&&y>0&&x<=n&&y<=m;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    //FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        pair<int,int>ans;
        ans = {-1,-1};
        cin>>n>>m;
        cout<<"? "<<"1 1"<<endl;
        int dis;
        cin>>dis;
        if(dis==0){ cout<<"! 1 1"<<endl;continue;}
        int x = min(n,1+dis); int y = min(m,1+dis);
        if(x==1+dis&&y==1+dis)
        {
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>dis;
            if(dis==0)
            {cout<<"! "<<x<<" "<<y<<endl;continue;}
            int tx = dis;
            cout<<"? "<<x-tx<<" "<<y<<endl;
            cin>>dis;
            if(dis==0)
            {
                cout<<"! "<<x-tx<<" "<<y<<endl;
            }
            else cout<<"! "<<x<<" "<<y-tx<<endl;
        }
        if(x==1+dis)
        {
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>dis;
            if(dis==0)
            {cout<<"! "<<x<<" "<<y<<endl;}
            else cout<<x-dis<<" "<<y<<endl;
        }
        else
        {
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>dis;
            if(dis==0)
            {cout<<"! "<<x<<" "<<y<<endl;continue;}
            else cout<<x<<" "<<y-dis<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
