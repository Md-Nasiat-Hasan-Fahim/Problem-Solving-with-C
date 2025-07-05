#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
 
typedef tree<int , null_type, less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

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
        int m,n;
        cin>>m>>n;
        vector<string>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        vector<pair<int,int>>pos;
        for(int i=0;i<n;i++)
        {
            ordered_multiset st;
            int cnt = 0;
            for(int j=0;j<m;j++)
            {
                cnt+=st.order_of_key(vec[i][m-j-1]);
                st.insert(vec[i][m-j-1]);
            }
            pos.push_back({cnt,i});
        }
        sort(all(pos));
        if(tttttttt>1) cout<<endl;
        for(int i=0;i<n;i++)
        cout<<vec[pos[i].second]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
