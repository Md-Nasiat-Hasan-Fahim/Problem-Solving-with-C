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
        sort(vec.begin()+1,vec.end());
        int mn = INT_MIN;
        int cnt[n+2]={0};
        for(int i=1;i<=n;i++)
        {
            cnt[i]+=cnt[i-1];
            vec[i]+=cnt[i];
            //cout<<cnt[i]<<endl;
            mn = max(vec[i],mn);
            cnt[i+1]-=vec[i];
        }
        cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
