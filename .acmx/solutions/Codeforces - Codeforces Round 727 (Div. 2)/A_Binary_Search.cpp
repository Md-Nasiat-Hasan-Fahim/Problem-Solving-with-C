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
vector<int>vec;

bool bs(int x)
{
    int lo = 0, hi = vec.size()-1;
    while(hi-lo>1)
    {
        int mid = (hi+lo)/2;
        if(vec[mid]>x) hi = mid-1;
        else if(vec[mid]<x) lo=mid+1;
        else return true;
    }
    return vec[hi]==x||vec[lo]==x;
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
        cin>>n>>q;
        vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        while(q--)
        {
            int x;
            cin>>x;
            if(bs(x)) YES;
            else NO;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
