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
        vector<int>vec;
        multiset<int>st;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            st.insert(a);
            vec.pb(a);
        }
        sort(all(vec));
        reverse(all(vec));
        stack<int>stc;
        for(int i=0;i<n/2;i++)
        {
            stc.push(vec[i]);
            st.erase(st.find(vec[i]));
        }
        bool ans = true;
        int p = 3;
        while(!st.empty()&&!stc.empty())
        {
            int x = stc.top();
            stc.pop();
            auto it1 = st.lower_bound(x);
            if(it1==st.begin())
            {
                ans=false;
                break;
            }
            it1--;
            st.erase(it1);
            auto it2 = st.lower_bound(x);
            if(it2==st.begin())
            {
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
