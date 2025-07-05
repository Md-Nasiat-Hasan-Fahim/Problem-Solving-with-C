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
        vector<int>vec(n-1);
        for(int i=0;i<n-1;i++) cin>>vec[i];
        int x = (n*(n+1))/2;
        multiset<int>st;
        int er=-1;
        if(vec.back()>x)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(vec.back()!=x) vec.pb(x);
        for(int i=vec.size()-1;i>0;i--)
        {
            int y = vec[i]-vec[i-1];
            if(st.count(y)||y>n)
            {
                er = i;
                break;
            }
            st.insert(y);
        }
        for(int i=0;i<er-1;i++)
        {
            int y = vec[i+1]-vec[i];
            st.insert(y);
        }
        int cnt = 0;
        if(vec[0]<=n&&!st.count(vec[0])) st.insert(vec[0]);
        for(int i=1;i<=n;i++)
        {
            if(!st.count(i)) cnt+=i;
        }
        //cout<<er<<" "<<cnt<<endl;
        if((er==-1&&cnt==vec[0])||((er>-1)&&vec[er-1]+cnt==vec[er])||(er==-1&&cnt==0)) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
