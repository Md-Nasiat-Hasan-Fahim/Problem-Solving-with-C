#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_multiset tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update>

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
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        ordered_multiset st;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            st.insert(vec[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(k)
            {
                int tem = st.order_of_key(k+1);
                int x = tem+min((int)st.size()-tem-1,k);
                tem = st.order_of_key(k);
                int y = tem+min((int)st.size()-tem,k );
                //cout<<vec[i]<<" "<<x<<" "<<y<<endl;
                if(vec[i]<=k) cout<<"1";
                else if(x<y)
                {
                    cout<<"1";
                    k--;
                }
                else cout<<"0";
            }
            else cout<<"0";
            st.erase(st.find_by_order(st.order_of_key(vec[i])));
        }
        cout<<endl;
        //cout<<st.size()<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
