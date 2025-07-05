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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string tem = s+"-";
        int ans = -1;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            if(tem[i+1]=='-') vec.pb(i);
        }
        for(int i=0;i<n;i++)
        {
            if(tem[i]=='-')
            {
                int x = *lower_bound(all(vec),i);
                //cout<<x<<endl;
                ans = max(ans,x-i);
            }
        }
        vec.clear();
        tem = "-"+s;
        for(int i=n;i>0;i--)
        {
            if(tem[i-1]=='-')
            vec.pb(i);
        }
        sort(all(vec));
        for(int i=n;i>-1;i--)
        {
            if(tem[i]=='-')
            {
                int x = *lower_bound(all(vec),i);
                //cout<<i<<" "<<x<<endl;
                ans = max(ans,i-x);
            }
        }
        if(ans==-1||ans==0) cout<<"-1\n"<<endl;
        else
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
