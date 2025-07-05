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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        //cout<<"Case "<<z<<": ";
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++) cin>>vec[i];
        vector<int>cum(n+1);
        cum[1]=vec[1];
        for(int i=2;i<=n;i++) cum[i]+=vec[i]+cum[i-1];
        int x = cum[n];
        int mn = INT_MAX;
        if(x==0) mn = 0;
        queue<int>q;
        for(int i=1;i*i<=x;i++) if(x%i==0){q.push(i);q.push(x/i);}
        while(!q.empty())
        {
            int y = q.front();
            q.pop();
            bool ans = true;
            int lo = 0;
            int cnt = 0;
            for(int hi = 1;hi<=n;hi++)
            {
                if(cum[hi]-cum[lo]==y)
                {
                    cnt+=hi-lo-1;
                    lo = hi;
                }
                else if(cum[hi]-cum[lo]>y)
                {
                    ans = false;
                    break;
                }
            }
            if(ans) mn = min(cnt,mn);
        }
        cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
