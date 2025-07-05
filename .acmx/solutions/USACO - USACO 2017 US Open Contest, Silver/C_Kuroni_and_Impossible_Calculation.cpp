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
        int n,m;
        cin>>n>>m;
        multiset<int>st;
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(st.count(a))
            {
                ans=0;
            }
            st.insert(a);
        }
        if(ans)
        {
            int cnt = 0;
            while(st.size()>1)
            {
                cnt++;
                int a = *st.begin();
                st.erase(st.begin());
                int x = (cnt)*(*st.begin()-a);
                x%=m;
                x = x*(n-cnt);
                x%=m;
                ans = ans*x;
                ans%=m;
                cout<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
