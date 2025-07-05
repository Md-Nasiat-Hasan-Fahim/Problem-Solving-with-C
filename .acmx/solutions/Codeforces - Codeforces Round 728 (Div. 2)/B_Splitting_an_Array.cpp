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

int n,k;
vector<int>vec;
int ans;

bool abc(int x)
{
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+vec[i]>x)
        {
            cnt++;
            sum = 0;
        }
        sum+=vec[i];
    }
    if(sum) cnt++;
    ans = cnt;
    return cnt<=k;
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
        cin>>n>>k;
        vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int lo = *max_element(all(vec)), hi = *max_element(all(vec));
        while(!abc(hi)) hi*=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid+1;
        }
        if(abc(lo)) cout<<lo<<endl;
        else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
