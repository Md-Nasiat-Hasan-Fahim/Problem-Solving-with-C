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

int ncr(int n, int r)
{
    int cnt = 1;
    for(int i=1;i<=r;i++)
    {
        cnt = (cnt*(n-i+1))/i;
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
        //cout<<"Case "<<z<<": ";
        int n,m=3,k=2;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int c = upper_bound(all(vec),vec[i]+k)-vec.begin()-i;
            if(c-1>=m-1) ans+=ncr(c-1,m-1);
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
