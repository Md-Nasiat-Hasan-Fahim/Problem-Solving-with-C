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

int abc(int x)
{
    int ct1 = lower_bound(all(vec),x)-vec.begin();
    int ct2 = vec.end()-upper_bound(all(vec),x);
    int cnt1 = 0;
    for(int i=0;i<vec.size();i++)
    {
        cnt1+=min(abs(vec[i]-x),abs(vec[i]-x+1));
    }
    int cnt2 = 0;
    for(int i=0;i<vec.size();i++)
    {
        cnt2+=min(abs(vec[i]-x),abs(vec[i]-x-1));
    }
    return min(cnt1,cnt2);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vec.assign(n,0);
        for(int i=0;i<n;i++) cin>>vec[i];
        int sum = accumulate(all(vec),0LL);
        int ct = ceil(1.0*sum/n);
        cout<<sum<<" "<<ct<<endl;
        sort(all(vec));
        cout<<(abc(ct),abc(ct-1))<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
