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
        int n,x;
        cin>>n>>x;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        for(int i=1;i<n;i++) vec[i]+=vec[i-1];
        int day = 0;
        int cnt = 0;
        for(int i=n-1;i>-1;i--)
        {
            //check(vec[i]);
            if(x>=vec[i])
            {
                int dc = (x-vec[i])/(i+1);
                dc++;
                if(dc>day)
                {
                    cnt+=((dc-day)*(i+1));
                    day=dc;
                }
                //cout<<day<<endl;
            }
        }
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
