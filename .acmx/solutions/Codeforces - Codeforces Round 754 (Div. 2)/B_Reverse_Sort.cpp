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
        int n;
        cin>>n;
        string s;
        cin>>s;
        priority_queue<int>z;
        set<int>o;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')z.push(i);
            else o.insert(i);
        }
        set<int>st;
        while(z.size()&&o.size()&&z.top()>*o.begin())
        {
            st.insert(z.top());z.pop();
            st.insert(*o.begin());o.erase(o.begin());
        }
        if(st.size())
        {
            cout<<"1"<<endl;
            cout<<st.size()<<" ";
            while(!st.empty())
            {
                cout<<*st.begin()+1<<" ";
                st.erase(st.begin());
            }
            cout<<endl;
        }
        else cout<<0<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
