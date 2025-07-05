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
        multiset<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            char c;
            int a;
            cin>>c>>a;
            if(c=='L'){
                st.insert({0,1});
                st.insert({a+1,-1});
            }
            else {
                st.insert({a,1});
                st.insert({mod,-1});
            }
        }
        int cnt = 0;
        int mx = INT_MIN;
        while(!st.empty())
        {
            cnt+=st.begin()->second;
            //cout<<cnt<<endl;
            mx=max(cnt,mx);
            st.erase(st.begin());
        }
        cout<<n-mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
