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
vector<int>a,b;
int n;

bool abc(int x)
{
    int tot = n+x;
    int rnd = (tot)-(tot/4);
    int t1x = min(rnd,x);
    int t1y = rnd-x;
    int c1 = t1x*100;
    if(t1y) c1+=a[t1y-1];
    int t2x = min(rnd,n);
    int c2 = 0;
    if(t2x) c2+=b[t2x-1];
    //if(x==3) cout<<c1<<" "<<a[2]<<" "<<c2<<endl;
    return c1>=c2; 
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
        cin>>n;
        a.resize(n);
        b.resize(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(all(a));sort(all(b));
        reverse(all(a));reverse(all(b));
        for(int i=1;i<n;i++) {a[i]+=a[i-1];}
        for(int i=1;i<n;i++) b[i]+=b[i-1];
        int lo = 0, hi = 1;
        while(!abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid+1;
        }
        //cout<<abc(3)<<endl;
        if(abc(lo)) cout<<lo<<endl;
        else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
