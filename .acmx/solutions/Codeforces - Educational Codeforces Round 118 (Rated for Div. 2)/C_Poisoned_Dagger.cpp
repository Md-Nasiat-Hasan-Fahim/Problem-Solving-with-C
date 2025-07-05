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
int n,h;

bool abc(int k,vector<int> &vec)
{
    int cnt = 0;
    int sti = 0;
    int ed = 0;
    while(sti<n)
    {
        int ts = sti;
        ed = sti;
        while(ts<n)
        {
            ed = upper_bound(all(vec),vec[ts]+k) - vec.begin() - 1;
            //if(k==250) cout<<ts<<" "<<ed<<endl;
            if(ts==ed) break;
            ts = ed;
        }
        //if(k==250) cout<<sti<<" "<<ed<<" "<<cnt<<endl;
        cnt+=vec[ed]+k-vec[sti];
        sti=ed+1;
    }
    return cnt>=h;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>n>>h;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int lo = 0, hi = h;
        while(hi-lo>1)
        {
            int mid = (hi-lo)/2 + lo;
            if(abc(mid,vec)) hi = mid;
            else lo = mid;
        }
        if(abc(lo,vec)) cout<<lo<<endl;
        else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
