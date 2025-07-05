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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n,w,h;
        cin>>n>>w>>h;
        vector<int>ck(n+2);
        vector<int>cv(n+2);
        for(int i=1;i<=n;i++) cin>>ck[i];
        for(int i=1;i<=n;i++) cin>>cv[i];
        bool ans = true;
        int mn = INT_MIN, mx = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int x = ck[i]-cv[i]-w+h;
            int y = ck[i]-cv[i]+w-h;
            ///cout<<i<<" "<<x<<" "<<y<<" "<<mn<<" "<<mx<<endl;
            if((x>=mn&&x<=mx)&&(y>=mn&&y<=mx))
            {
                mn = max(mn,x);
                mx = min(mx,y);
            }
            else if((x>=mn&&x<=mx))
            {
                mn = max(mn,x);
            }
            else if((y>=mn&&y<=mx))
            {
                mx = min(mx,y);
            }
            else if(x<=mn&&mx<=y)
            {
                mn=mn;
                mx=mx;
            }
            else
            {
                ans=false;
                break;
            }
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
