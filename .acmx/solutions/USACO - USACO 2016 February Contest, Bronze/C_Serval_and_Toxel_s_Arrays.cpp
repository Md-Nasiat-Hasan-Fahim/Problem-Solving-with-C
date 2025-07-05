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
const int mx = 4e5+5;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>vec(mx),last(mx),ara;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ara.pb(a);
            st.insert(a);
        }
        int tm = 0;
        while(m--)
        {
            tm++;
            int p,a;
            cin>>p>>a;
            st.insert(a);
            vec[ara[p-1]]+=tm-last[ara[p-1]];
            last[ara[p-1]]=-1;
            last[a]=tm;
            ara[p-1]=a;
        }
        tm++;
        while(!st.empty())
        {
            int a = *st.begin();
            st.erase(st.begin());
            if(last[a]!=-1)
            vec[a]+=tm-last[a];
        }
        int cnt = 0;
        for(int i=1;i<mx;i++)
        {
            if(vec[i])
            {
                if(vec[i]==1) cnt+=n-1;
                else cnt+=vec[i]*((n-1+n-vec[i]))/2;
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
