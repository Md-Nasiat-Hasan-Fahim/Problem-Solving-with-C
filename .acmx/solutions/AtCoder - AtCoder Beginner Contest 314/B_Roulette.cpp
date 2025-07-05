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
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;cin>>n;
        vector<int>vec[n+1];
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            for(int j=0;j<a;j++)
            {
                int b;
                cin>>b;
                vec[i].pb(b);
            }
        }
        int x;
        cin>>x;
        set<pair<int,int>>st;
        for(int i=1;i<=n;i++)
        {
            bool flag = false;
            for(int j=0;j<vec[i].size();j++) if(x==vec[i][j]) flag = true;
            if(flag) st.insert({vec[i].size(),i});
        }
        vector<int>ans;
        if(st.size())
        {
            int x = st.begin()->first;
            int cnt = 0;
            while(!st.empty()&&st.begin()->first==x)
            {
                cnt++;
                ans.pb(st.begin()->second);
                st.erase(st.begin());
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
