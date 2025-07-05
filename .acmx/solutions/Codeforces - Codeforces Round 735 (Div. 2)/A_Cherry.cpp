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
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        vector<int>ara(1e6+1);
        vector<int>vec(n);
        for(int i=0;i<n;i++) {cin>>vec[i];ara[vec[i]]++;}
        int mx = max(vec[0],vec[1]);
        int mn = min(vec[0],vec[1]);
        int cnt = mn*mx;
        multiset<int>st;
        st.insert(vec[0]);st.insert(vec[1]);
        for(int i=3,j=0;i<n;i++)
        {
            if(vec[i]>mn)
            {
                while(st.size()>2&&(vec[j]!=mx||(vec[j]==mx&&st.count(mx)>1))) {st.erase(vec[j]);j++;cnt=max(cnt,(*(prev(st.end(),1)))*(*prev(st.end(),2)));}
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
