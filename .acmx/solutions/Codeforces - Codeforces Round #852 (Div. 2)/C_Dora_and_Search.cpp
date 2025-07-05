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
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int last = INT_MAX, index1 = 0, index2 = 0; bool ans = false;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            if(upper_bound(all(st),vec[i])!=st.end())
            {
                //cout<<i<<" "<<last<<endl;
                if(last)
                {
                    if(vec[i]>last)
                    {
                        index2 = i;
                        ans=true;
                        break;
                    }
                    else
                    {
                        index1=i;
                        last = vec[i];
                    }
                }
            }
            st.insert(vec[i]);
        }
        if(ans)
        cout<<index1<<" "<<index2+1<<endl;
        else cout<<"-1\n";
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
