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
        unordered_map<string,string> mp;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            mp[s2]=s1;
        }
        for(int i=0;i<m;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            string pq;
            for(int i=0;i<s2.size()-1;i++) pq.pb(s2[i]);
            cout<<s1<<" "<<s2<<" #"<<mp[pq]<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
