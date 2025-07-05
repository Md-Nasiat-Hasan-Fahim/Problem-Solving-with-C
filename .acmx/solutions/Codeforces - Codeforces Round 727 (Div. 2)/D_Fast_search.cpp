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
vector<int>vec;

int bsl(int x)
{
    int lo=0,hi = vec.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi+lo)/2;
        if(vec[mid]>=x) hi = mid;
        else lo = mid+1;
    }
    if(vec[lo]>=x) return lo;
    else if(vec[hi]>=x) return hi;
    else return vec.size()+1;
}

int bsr(int x)
{
    int lo = 0, hi = vec.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi+lo)/2;
        if(vec[mid]<=x) lo = mid;
        else hi = mid-1;
    }
    if(vec[hi]<=x) return hi;
    else if(vec[lo]<=x) return lo;
    else return -1;
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
        int n,q;
        cin>>n;
        vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<max(0LL,bsr(r)-bsl(l)+1)<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}

