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
    int t=1;
    //cin>>t;

    for(int z=1;z<=t;z++)
    {
        int n,d;
        cin>>n>>d;
        int x = (n*(n-1))/2;
        if(n*d>x)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        int ara[n+1];
        for(int i=1;i<n+1;i++) ara[i]=2*d;
        for(int i=1;i<=n;i++)
        {
            if(ara[i]==0) continue;
            for(int j=1;j<=n;j++)
            {
                if(!ara[j]||i==j) continue;
                cout<<i<<" "<<j<<endl;
                ara[j]--;
                ara[i]--;
                if(ara[i]==0) break;
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
