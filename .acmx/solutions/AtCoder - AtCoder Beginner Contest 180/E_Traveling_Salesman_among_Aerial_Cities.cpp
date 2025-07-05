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
        vector<set<int>>vec(n+1);
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            vec[a].insert(b);
            vec[b].insert(a);
        }
        multiset<int>ans;
        set<int>st;
        for(int i=1;i<=n;i++)
        {
            if(vec[i].size()==1) st.insert(i);
        }
        while(!st.empty())
        {
            int x = *st.begin();
            int y = *vec[x].begin();
            ans.insert(vec[y].size());
            while(!vec[y].empty())
            {
                int a = *vec[y].begin();
                vec[y].erase(vec[y].begin());
                if(vec[a].size()==1)
                {
                    vec[a].erase(vec[a].begin());
                    auto it = st.find(a);
                    if(it!=st.end()) st.erase(it);
                }
                else
                {
                    if(*vec[a].begin()==y)
                    {
                        vec[a].erase(vec[a].begin());
                        st.insert(*vec[a].begin());
                        int x = *vec[a].begin();
                        vec[x].erase(vec[x].find(a));
                        vec[a].clear();
                    }
                    else
                    {
                        st.insert(*vec[a].begin());
                        int x = *vec[a].begin();
                        vec[x].erase(vec[x].find(a));
                        vec[a].clear();
                    }
                }
            }
        }
        while(!ans.empty())
        {
            cout<<*ans.begin()<<" ";
            ans.erase(ans.begin());
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
