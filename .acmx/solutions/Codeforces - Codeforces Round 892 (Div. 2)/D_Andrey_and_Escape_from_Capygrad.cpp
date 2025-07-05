#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
 
typedef tree<int , null_type, less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        unordered_map<int,int,custom_hash>mp;
        int n;
        cin>>n;
        ordered_set st;
        for(int i=0;i<n;i++)
        {
            int l,r,a,b;
            cin>>l>>r>>a>>b;
            int j = st.order_of_key(b+1);
            //cout<<j<<endl;
            j--;
            int mn = l,mx = b;
            if(j<st.size())
            for(;j>-1&&mp[*st.find_by_order(j)]>=l;j++)
            {
                int xy = *st.find_by_order(j);
                mn = min(xy,mn);
                mx = max(mx,mp[xy]);
                st.erase(st.find_by_order(j));
            }
            //cout<<mn<<" "<<mx<<endl;
            //if(mp[l]<b) mp[l]=b;
            st.insert(mn);
            if(mp[mn]<mx) mp[mn]=mx;
        }
        int m;
        cin>>m;
        int z = st.size();
        while(m--)
        {
            int a;
            cin>>a;
            int j = st.order_of_key(a+1)-1;
            int y = -1;
            if(j<z&&j>-1)y=*st.find_by_order(j);
            cout<<max(mp[y],a)<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
