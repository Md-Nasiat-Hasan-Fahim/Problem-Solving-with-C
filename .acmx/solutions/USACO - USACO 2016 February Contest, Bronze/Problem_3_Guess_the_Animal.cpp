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

set<string> intersection(set<string> &st1, set<string> &st2)
{
    set<string>rem;
    for(auto at:st1)
    {
        if(st2.count(at)) rem.insert(at);
    }
    return rem;
}

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
        vector<set<string>>vec(n+1);
        for(int i=0;i<n;i++)
        {
            string s;
            int m;
            cin>>s>>m;
            for(int j=0;j<m;j++)
            {
                cin>>s;
                vec[i].insert(s);
            }
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<string> st = intersection(vec[i],vec[j]);
                mx = max(mx,st.size()+1LL);
            }
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
