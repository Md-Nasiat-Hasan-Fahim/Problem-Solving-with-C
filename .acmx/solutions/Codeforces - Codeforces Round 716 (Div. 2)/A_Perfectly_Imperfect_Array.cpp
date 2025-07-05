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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        bool ans = false;
        vec.pb(1);
        n++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a = sqrt(vec[i]*vec[j]);
                //cout<<a<<endl;
                if(a*a!=vec[i]*vec[j])
                {
                    //cout<<a<<" "<<i<<" "<<j<<endl;
                    ans=true;
                }
            }
        }
        if(ans) YES;
        else NO;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
