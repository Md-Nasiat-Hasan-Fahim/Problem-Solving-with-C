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

int change(int x)
{
    int cnt = 0;
    for(int i=1,j=1;i<=x;i=i*10,j++)
    {
        if(j%2==1)
        {
            int y = x/i;
            //cout<<y<<" ";
            cnt+=y*j-(y*(j-1));
        }
        else
        {
            int y = x/i;
            //cout<<y<<" ";
            cnt+=y*j-(y*(j-1));
        }
        //cout<<cnt<<endl;
    }
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int l,r;
        cin>>l>>r;
        cout<<change(r)-change(l)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
