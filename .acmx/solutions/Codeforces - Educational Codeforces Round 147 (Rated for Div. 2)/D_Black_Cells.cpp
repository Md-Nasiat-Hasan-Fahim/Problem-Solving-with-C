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
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int cnt = LONG_LONG_MAX;
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i].first;
        for(int i=0;i<n;i++) cin>>vec[i].second;
        multiset<int>st;
        int last = 0;
        int op = 0;
        int mm = 0;
        int i;
        for(i=0;i<n;i++)
        {
            op+=(vec[i].second-last)+2;
            mm+=(vec[i].second-vec[i].first+1);
            last = vec[i].second;
            st.insert((vec[i].second-vec[i].first+1));
            if(mm>=k)
            {
                cnt = min(cnt,op-(mm-k));
            }
            while(!st.empty()&&(mm-(*st.begin()))>=k)
            {
                op-=2;
                cnt=min(cnt,op);
                mm-=*st.begin();
                st.erase(st.begin());
            }
            if(mm>=k)
            {
                cnt = min(cnt,op-(mm-k));
            }
        }
        if(mm>=k)
        {
            cnt = min(op-(mm-k),cnt);
        }
        if(cnt==LONG_LONG_MAX)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
