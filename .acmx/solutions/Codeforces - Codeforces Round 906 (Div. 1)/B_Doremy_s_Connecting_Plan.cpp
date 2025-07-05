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
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,c;
        cin>>n>>c;
        vector<int>par(n+1),ara(n+1);
        set<pair<int,int>>st;
        for(int i=1;i<=n;i++)
        {
            cin>>ara[i];
            st.insert({c*i,i});
        }
        int cnt = ara[1];
        par[1]=1;
        st.erase({c,1});
        for(int i=2;i<=n;i++)
        {
            if(ara[i]>=i*c)
            {
                st.erase({i*c,i});
                cnt+=ara[i];
                par[i]=1;
            }
        }
        while(st.size()&&ara[st.begin()->second]+cnt>=st.begin()->first)
        {
            cnt+=ara[st.begin()->second];
            par[st.begin()->second]=1;
            st.erase(st.begin());
        }
        bool ans = true;
        for(int i=1;i<=n;i++) if(par[i]!=1) ans = false;
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
