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
        int n,q;
        cin>>n>>q;
        vector<set<int>>vec(n+1);
        int cnt = n;
        while(q--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int u,v;
                cin>>u>>v;
                if(vec[u].empty()) cnt--;
                if(vec[v].empty()) cnt--;
                vec[u].insert(v);
                vec[v].insert(u);
            }
            else
            {
                int u;
                cin>>u;
                if(!vec[u].empty()){
                cnt++;
                while(!vec[u].empty())
                {
                    int x = *vec[u].begin();
                    vec[u].erase(vec[u].begin());
                    if(vec[x].empty()) continue;
                    auto it = vec[x].find(u);
                    if(it!=vec[x].end()) vec[x].erase(it);
                    if(vec[x].empty()) cnt++;

                }
                }
            }
            cout<<cnt<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
