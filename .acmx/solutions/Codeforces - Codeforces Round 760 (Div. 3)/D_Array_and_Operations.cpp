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
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        set<int>st;
        multiset<int>mst;
        reverse(all(vec));
        k = 2*k;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(i<k)
            {
                st.insert(vec[i]);
                mst.insert(vec[i]);
            }
            else sum+=vec[i];
        }
        int mx = 0;
        while(!st.empty())
        {
            int a = *st.begin();
            st.erase(st.begin());
            if(mst.count(a)>mx) mx = mst.count(a);
        }
        sum+=max(0LL,(mx-k/2));
        cout<<sum<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
