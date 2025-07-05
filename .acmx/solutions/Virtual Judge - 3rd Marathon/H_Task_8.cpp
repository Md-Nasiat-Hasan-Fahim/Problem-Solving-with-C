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

struct PairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &v) const
    {
        return std::hash<T1>()(v.first) ^ hash<T2>()(v.second) << 1;    
        //return std::hash<T1>{}(v.first) ^ hash<T2>{}(v.second) << 1;    //same as above
    }
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        unordered_map<pair<int,int>,string,PairHash>mp;
        for(int i=0;i<n;i++)
        {
            int a,b;
            string s;
            cin>>a>>b>>s;
            mp[{a,b}]=s;
        }
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            cout<<mp[{a,b}]<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
