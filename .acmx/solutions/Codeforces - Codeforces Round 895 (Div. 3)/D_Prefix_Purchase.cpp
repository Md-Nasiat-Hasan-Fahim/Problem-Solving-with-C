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
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++) cin>>vec[i];
        int k; cin>>k;
        auto mn = vec;
        int plc[n+1]={0};
        plc[n]=n;
        for(int i=n-1;i>0;i--)
        {
            if(mn[i]>=mn[i+1])
            {
                mn[i]=mn[i+1];
                plc[i]=plc[i+1];
            }
            else
            {
                plc[i]=i;
            }
        }
        int ara[n+1]={0};
        int prev = 0;
        for(int i=1;i<=n;)
        {
            int xy = mn[i]-prev;
            int x = k/xy;
            int ti = i;
            while(plc[ti]+1<=n)
            {
                int txy = mn[plc[ti]+1] - prev;
                if(x*txy>k) break;
                ti = plc[ti]+1;
            }
            k = k%xy;
            ara[i]+=x;
            if(plc[ti]+1<=n) ara[plc[ti]+1]-=x;
            prev = mn[ti];
            i = plc[ti]+1;
        }
        for(int i=1;i<=n;i++) ara[i]+=ara[i-1];
        for(int i=1;i<=n;i++) cout<<ara[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
