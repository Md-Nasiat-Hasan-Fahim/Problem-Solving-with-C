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
        int n,k;
        cin>>n>>k;
        vector<int>vec(k);
        for(int i=0;i<k;i++)
        cin>>vec[i];
        bool ans = true;
        int lim = ceil(1.0*vec[0]/(n-k+1));
        for(int i=1;i<k;i++)
        {
            int x = vec[i]-vec[i-1];
            if(x<lim)
            {
                ans=false;
                break;
            }
            lim=max(lim,x);
        }
        if(ans) YES;
        else NO;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
