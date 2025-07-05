#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ara[32] = {0};
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            for(int i=0;i<31;i++)
            {
                if((a&(1<<i))) ara[i]++;
            }
        }
        int mn = INT_MAX;
        for(int i=0;i<31;i++)
        {
            if(ara[i])
            {
                mn = ara[i];
                break;
            }
        }
        if(mn==INT_MAX)
        {
            for(int i=1;i<=n;i++)
            cout<<i<<" ";
        }
        else
        {
            for(int i=0;i<31;i++)
            {
            if(ara[i])
            {
                mn = __gcd(mn,ara[i]);
            }
            }
            int i=1;
            stack<int>st;
            for(;i*i<mn;i++)
            {
                if(mn%i==0){
                st.push(mn/i);
                cout<<i<<" ";
                }
            }
            if(i*i==mn) st.push(i);
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
