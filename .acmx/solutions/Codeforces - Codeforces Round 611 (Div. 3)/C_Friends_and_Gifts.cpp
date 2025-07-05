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
        set<int>st;
        priority_queue<int>pq;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            st.insert(i);
        }
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            if(vec[i]!=0)st.erase(vec[i]);
        }
        for(int i=n-1;i>-1;i--)
        {
            if(!vec[i])
            {
                int a = *st.begin();
                st.erase(st.begin());
                if(a==i+1)
                {
                    vec[i]=*st.begin();
                    st.erase(st.begin());
                    st.insert(a);
                }
                else vec[i]=a;
            }
        }
        for(int i=0;i<n;i++) cout<<vec[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
