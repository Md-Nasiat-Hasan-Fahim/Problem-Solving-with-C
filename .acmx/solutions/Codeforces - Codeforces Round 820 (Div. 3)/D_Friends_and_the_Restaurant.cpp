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
        vector<int>one(n),two(n);
        for(int i=0;i<n;i++) cin>>one[i];
        for(int i=0;i<n;i++) cin>>two[i];
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            vec.pb(two[i]-one[i]);
        }
        sort(all(vec));
        int i=0, j = n-1;
        int cnt = 0;
        while(i<j)
        {
            if(vec[i]+vec[j]>=0)
            {
                cnt++;
                i++;
                j--;
            }
            else i++;
        }
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
