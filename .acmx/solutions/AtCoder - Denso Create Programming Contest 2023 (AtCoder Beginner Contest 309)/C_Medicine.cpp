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
    FastIO;
    int Master0fTheSEA=1;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,k;
        cin>>n>>k;
        multiset<pair<int,int>>st;
        int mx = LONG_LONG_MIN;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            st.insert({1,b});
            st.insert({a+1,-b});
            mx = max(mx,a+1);
        }
        int cnt = 0;
        while(!st.empty())
        {
            int p = st.begin()->first;
            while(!st.empty()&&st.begin()->first==p)
            {
                cnt+=st.begin()->second;
                st.erase(st.begin());
            }
            if(cnt<=k)
            {
                mx = p;
                break;
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
