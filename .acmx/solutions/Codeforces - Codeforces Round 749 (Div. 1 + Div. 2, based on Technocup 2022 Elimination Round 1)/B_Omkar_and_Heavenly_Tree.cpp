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
        int n,m;
        cin>>n>>m;
        set<int>st;
        for(int i=2;i<=n;i++)
        {
            st.insert(i);
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(b==1)
            {
                if(st.count(a)&&st.count(c)) st.erase(a);
                vec.pb({a,c});
            }
        }
        for(int i=0;i<vec.size();i++) cout<<vec[i].first<<" "<<vec[i].second<<endl;
        while(!st.empty())
        {
            cout<<"1 "<<*st.begin()<<endl;
            st.erase(st.begin());
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
