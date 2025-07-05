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
        int n;
        cin>>n;
        unordered_map<string,int> mp;
        set<pair<int,string>>st;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a==1)
            {
                string s; int x;
                cin>>s>>x;
                mp[s]=x;
                st.insert({x,s});
            }
            else if(a==2)
            {
                string s; int x;
                cin>>s>>x;
                int y = mp[s];
                st.erase({y,s});
                st.insert({x,s});
                mp[s]=x;
            }
            else
            {
                string s;
                cin>>s;
                cout<<st.begin()->second<<" "<<i+1<<endl;
                st.erase(st.begin());
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
