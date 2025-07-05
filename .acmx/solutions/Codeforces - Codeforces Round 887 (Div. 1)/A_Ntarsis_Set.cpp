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
        set<int>st;
        int mx = -1;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            mx = max(a,mx);
            vec.pb(a);
        }
        for(int i=1;i<=mx;i++) st.insert(i);
        for(int i=0;i<n;i++)
        {
            st.erase(vec[i]);
        }
        if(st.size()==0)
        {
            cout<<k*n+1<<endl;
        }
        else if(*st.begin()==1)
        {
            cout<<"1"<<endl;
        }
        if(k==1)
        {
            cout<<*st.begin()+n*(k-1)<<endl;
        }
        else if(*st.begin()<=st.size())
        {
            vector<int>tem;
            set<int>stt;
            for(auto x:st) tem.pb(x);
            for(auto x:st)
            {
                if(x<st.size())stt.insert(tem[x-1]); 
            }
            k-=2;
            int x = k/stt.size();
            int y = k%stt.size();
            while(y--) stt.erase(stt.begin());
            cout<<*stt.begin()+x*n<<endl;
        }
        else
        {
            cout<<*st.begin()+n*(k-1)<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
