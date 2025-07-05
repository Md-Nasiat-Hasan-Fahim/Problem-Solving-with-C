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
        int n,k,x;
        cin>>n>>k>>x;
        multiset<int>st,pq;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            st.insert(a);
        }
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }
        int l = *st.begin();
        st.erase(st.begin());
        int cnt = 1;
        while(!st.empty())
        {
            int y = *st.begin()-l;
            if(y>x)
            {
                cnt++;
                pq.insert(y);
            }
            l = *st.begin();
            st.erase(st.begin());
        }
        while(!pq.empty()&&k)
        {
            int y = *pq.begin();
            int p = ceill((long double)1.0*y/x)-1;
            if(k>=p)
            {
                cnt--;
                k-=p;
            }
            else break;
            pq.erase(pq.begin());
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}