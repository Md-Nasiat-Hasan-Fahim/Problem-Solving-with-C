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
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m,x;
        cin>>n>>m>>x;
        vector<pair<int,int>>vec;
        vector<int>brick(n+2);
        multiset<pair<int,int>>st;
        for(int i=1;i<=m;i++) st.insert({0,i});
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            vec.pb({a,i});
        }
        sort(all(vec));
        for(int i=0;i<n;i++)
        {
            auto it = st.begin();
            int x = it->first+vec[i].first;
            int y = it->second;
            //cout<<x<<" "<<y<<endl;
            brick[vec[i].second]=y;
            st.erase(it);
            st.insert({x,y});
        }
        auto tp = st.begin();
        auto ed = prev(st.end());
        if(ed->first-tp->first<=x)
        {
            YES;
            for(int i=1;i<=n;i++)
            {
                cout<<brick[i]<<" ";
            }
            cout<<endl;
        }
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
