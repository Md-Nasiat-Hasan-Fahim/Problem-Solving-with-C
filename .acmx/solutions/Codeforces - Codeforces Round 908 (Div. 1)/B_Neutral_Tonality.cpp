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
        int n,m;
        cin>>n>>m;
        vector<int>vec1(n),vec2(m),ara(n+5),ans;
        for(int i=0;i<n;i++) cin>>vec1[i];
        for(int i=0;i<m;i++) cin>>vec2[i];
        sort(all(vec2));
        ara.back()=-1;
        for(int i=n-1;i>-1;i--)
        {
            ara[i]=max(vec1[i],ara[i+1]);
        }
        for(int i=0;i<ara.size();i++)
        {
            while(vec2.size()&&vec2.back()>=ara[i])
            {
                ans.pb(vec2.back());vec2.pop_back();
            }
            if(i<n) ans.pb(vec1[i]);
        }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
