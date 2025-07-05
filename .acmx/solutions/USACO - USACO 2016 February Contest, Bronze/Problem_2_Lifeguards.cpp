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
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>vec;
        vector<int>ara(1002);
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            vec.pb({a,b});
            ara[a]+=1;
            ara[b]-=1;
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            auto ara1 = ara;
            int cnt = 0;
            int a = vec[i].first;
            int b = vec[i].second;
            ara1[a]-=1;
            ara1[b]+=1;
            if(ara1[0]) cnt++;
            for(int j=1;j<=1000;j++)
            {
                ara1[j]+=ara1[j-1];
                if(ara1[j]) cnt++;
            }
            mx = max(cnt,mx);
            //cout<<i<<" "<<mx<<" "<<cnt<<endl;
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
