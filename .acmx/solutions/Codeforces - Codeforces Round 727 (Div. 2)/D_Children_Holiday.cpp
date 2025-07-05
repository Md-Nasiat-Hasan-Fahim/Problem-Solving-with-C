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
struct node{
    int t,r,z;
};

vector<node>vec;

int n,m;
int ans;

bool abc(int x)
{
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        node nd = vec[i];
        int a = (x/(nd.t*nd.z+nd.r));
        int b = (x%(nd.t*nd.z+nd.r));
        cnt+=a*nd.z+min(nd.z,(b/nd.t));
    }
    ans = cnt;
    return cnt>=n;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int t,r,z;
            cin>>t>>z>>r;
            vec.pb({t,r,z});
        }
        int lo = 0, hi = 1;
        while(!abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid+1;
        }
        int cnt;
        if(abc(lo)) cnt = lo;
        else cnt=hi;
        cout<<cnt<<endl;
        abc(cnt);
        ans = ans-n;
        for(int i=0;i<m;i++)
        {
            node nd = vec[i];
            int a = (cnt/(nd.t*nd.z+nd.r));
            int b = (cnt%(nd.t*nd.z+nd.r));
            int x = a*nd.z+min(nd.z,(b/nd.t));
            int y = min(ans,x);
            ans-=y;
            x-=y;
            cout<<x<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
