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
        int n,k;
        cin>>n>>k;
        vector<int>vec(k+3);
        vector<pair<int,int>>pr;
        for(int i=1;i<=k;i++)
        {
            int a,b;
            cin>>a>>b;
            pr.pb({b,i});
            vec[i]=a;
        }
        sort(all(pr));
        vector<pair<int,int>>pos;
        int cnt = 0;
        for(int i=0;i<2*n;i++)
        {
            cnt+=pr[i].first;
            pos.pb({vec[pr[i].second],pr[i].second});
        }
        sort(all(pos));
        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<pos[i].second<<" "<<pos[2*n-1-i].second<<endl;
        }
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
